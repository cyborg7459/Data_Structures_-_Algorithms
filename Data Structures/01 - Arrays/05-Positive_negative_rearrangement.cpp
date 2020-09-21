// An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively
// Rearrange positive and negative numbers in O(n) time and O(1) extra space

#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void rearrange(int arr[], int n) {
    int i = -1;
    for(int j=0; j<n; j++) {
        if(arr[j] < 0) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    int pos = i + 1, neg = 0;
    print(arr,n);
    cout << endl;
    while (pos < n && neg < pos && arr[neg] < 0)
    {
       swap(arr[neg], arr[pos]);
       print(arr,n);
       cout << endl;
       pos++;
       neg += 2;
    }
}

int main() {
    int arr[] = {-1, -2, -3, 4, 5, 6, -7, 8, 9};
    rearrange(arr,9);
    print(arr,9);
}
