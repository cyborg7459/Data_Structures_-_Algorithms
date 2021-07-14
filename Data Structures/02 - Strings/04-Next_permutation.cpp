// PS : Implement the next permutation function in a vector
// To implement the nextPermutation function, we first need to understand how next permutation actually works. In this, the permutation generated is always lexicographically greater than the previous
// one. However, this change is as minimum as possible. This means that the change takes place as right as possible. Since we lexicographically increase the vector, it means that at least one of the
// positions is increased in value. Since we want this position to be as right as possible, we start traversing from the right. As long as the elements keep increasing (meaning that the suffix is in
// decreasing order), we cannot make any swaps. As soon as we get the first element which is smaller than the element to it's right, we stop. Now, we want to make the change as minimal as possible, hence
// we'll check which element to it's right is greater than it, and as small as possible, and then swap with that element
// Now since we've achieved increase at one position it means that the vector is already lexicographically greater. Now the vector to the right of it must be made lexicographically smallest (increasing order)
// This would take O(N) only because while traversing back, we kept on going as long as the string was increasing, and then made the swap in such a way that the increasing order is not disturbed. Hence
// we simply reverse the string to the right of idx

#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &v, int start, int end) {
    while(start < end) {
        int temp = v[start];
        v[start] = v[end];
        v[end] = temp;
        start++;
        end--;
    }
}

vector<int> nextPermutation(int N, vector<int> arr){
    int idx = N-2;
    bool b = true;
    while(idx >= 0) {
        if(arr[idx] < arr[idx+1]) break;
        else idx--;
    }
    if(idx == -1) {
        reverse(arr, 0, N-1);
        return arr;
    }
    int num = arr[idx];
    int mx = 1000000007, mxi = -1;
    for(int i=idx+1; i<N; i++) {
        if(arr[i] > num && arr[i] < mx) {
            mx = arr[i];
            mxi = i;
        }
    }

    int temp = arr[idx];
    arr[idx] = arr[mxi];
    arr[mxi] = temp;

    reverse(arr, idx+1, N-1);
    return arr;
}

int main() {
    vector<int> v = {3,2,4,5,1,7,5,2};
    v = nextPermutation(v.size(), v);
    for(int t : v) cout << t << " ";
}
