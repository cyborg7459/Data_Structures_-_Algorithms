#include <bits/stdc++.h>
using namespace std;

print(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void countingSort(int arr[], int n) {
    int max = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    int temp[max] = {};
    int idx = 0;
    for(int i=0; i<n; i++)
        temp[arr[i]-1]++;
    for(int i=0; i<max; i++) {
        while(temp[i]!=0) {
            arr[idx] = i+1;
            idx++;
            temp[i]--;
        }
    }
}

int main() {
    int arr[10] = {1,3,5,3,1,8,1,45,1,23};
    countingSort(arr, 10);
    print(arr, 10);
}
