#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(const vector<int> &A, const vector<int> &B) {
    int n = A.size();
    int pre_sum = 0, start = 0;
    for(int i=0; i<n; i++) {
        pre_sum += A[i] - B[i];
        if(pre_sum < 0) {
            start = i+1;
            pre_sum = 0;
        }
    }
    if(start >= n) return -1;
    else {
        int i = start;
        int sum = 0;
        while(true) {
            sum += A[i] - B[i];
            if(sum < 0) return -1;
            i++;
            if(i == n) i = 0;
            if(i == start) break;
        }
    }
    return start;
}

int main() {
    vector<int> petrol = {2,4,3,5,10,7};
    vector<int> dist = {1,5,2,10,12,1};
    cout << canCompleteCircuit(petrol, dist);
}
