#include <bits/stdc++.h>
using namespace std;

int max_sum(int arr[], int n) {
    int res = 0, temp = 0;
    for(int i=0; i<n; i++) {
        temp += arr[i];
        res = max(res, temp);
        if(temp < 0)
            temp = 0;
    }
    return res;
}

int main() {
    int arr[8] = {1,1,1,-1,-1,1,1,1};
    cout << max_sum(arr, 8);
}
