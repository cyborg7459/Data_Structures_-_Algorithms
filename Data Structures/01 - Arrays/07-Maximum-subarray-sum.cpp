#include <bits/stdc++.h>
using namespace std;

int max_sum(int arr[], int n) {
    int best{}, sum{};
    for(int i=0; i<n; i++) {
        sum = max(arr[i], sum+arr[i]);
        best = max(sum, best);
    }
    return best;
}

int main() {
    int arr[8] = {-1,2,4,-3,5,2,-5,2};
    cout << max_sum(arr, 8) << endl;
}
