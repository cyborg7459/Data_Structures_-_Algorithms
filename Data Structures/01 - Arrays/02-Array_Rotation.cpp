#include <iostream>
using namespace std;

void rotate_by_one(int arr[], int n) {
    int t = arr[0];
    for(int i=0; i<n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = t;
}

void rotate(int arr[], int d, int n) {
    d = d % n;
    for(int i=0; i<d; i++)
        rotate_by_one(arr, n);
}

void  printArr(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    rotate(arr,125,10);
    printArr(arr, 10);
}
