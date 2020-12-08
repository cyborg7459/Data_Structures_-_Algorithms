#include <bits/stdc++.h>
using namespace std;

int Linear_Search(int num, int arr[], int len) {
    for(int i=0;i <len; i++) {
        if(arr[i]==num)
            return i+1;
    }
    return -1;
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout << Linear_Search(6,arr,10) << "\n";
    cout << Linear_Search(12,arr,10) << "\n";
}
