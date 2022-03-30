// An array contains both positive and negative numbers in random order. Rearrange the array elements so that positive and negative numbers are placed alternatively
// Rearrange positive and negative numbers in O(n) time and O(1) extra space
// EXPLANATION: For the first step, we'll separate out all positive and negative numbers by placing the negative numbers at the start of the array. Once this has been done,
// the next step is to replace every alternate positive number with a negative number. For this we'll use 2 pointers, one for positive numbers and other for negative numbers.
// The positive pointer would move single place at a time while the negative pointer would move 2 places at once

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
