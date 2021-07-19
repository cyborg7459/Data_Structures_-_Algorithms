// Expanation : If the range of elements in an array is of the order n^2, then counting sort does not help, inspite of having a linear time complexity. In this case, radix sort comes handy. If the number
// of digits of the numbers are not very large, then we can easily use radix sort to sort the array. In this, we sort the elements digit by digit, starting from the least significant and going to the most
// significant one

#include <bits/stdc++.h>
using namespace std;

void radixSort(vector<int> &v) {
    int n = v.size();
    int pos = 1;
    while(true) {
        vector<int> arr[11];
        int cnt = 0;
        for(int i=0; i<n; i++) {
            int t = v[i];
            string temp = to_string(t);
            if(temp.size() < pos) {
                cnt++;
                arr[0].push_back(i);
            }
            else {
                int dig = temp[temp.size() - pos] - '0';
                arr[dig+1].push_back(i);
            }
        }
        if(cnt == n) return;
        int idx = 0;
        vector<int> temp(n);
        for(vector<int> v1 : arr) {
            for(int i : v1) {
                temp[idx++] = v[i];
            }
        }
        v = temp;
        pos++;
    }
}

int main() {
    vector<int> v = {10,52,56,59,51,65,8,45,54,7,2,97,1,2,16,48,75,12,448,6,4,4};
    radixSort(v);
    for(int t : v) cout << t << " ";
}
