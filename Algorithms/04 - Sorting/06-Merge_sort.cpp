#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int l, int r) {
    for(int i=l; i<=r; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void merge(int arr[], int l, int m, int r) {
    cout << "Calling merge function for " << l << " to " << r << "\nThe array section after merging is : ";
    int n1 = (m-l+1), n2 = (r-m);
    int arr1[n1], arr2[n2];
    for(int i=l; i<=m; i++) arr1[i-l] = arr[i];
    for(int i=m+1; i<=r; i++) arr2[i-(m+1)] = arr[i];
    int i1 = 0, i2 = 0, idx = l;
    while(i1 < n1 && i2 < n2) {
        if(arr1[i1] < arr2[i2]) arr[idx++] = arr1[i1++];
        else arr[idx++] = arr2[i2++];
    }
    while(i1 < n1) arr[idx++] = arr1[i1++];
    while(i2 < n2) arr[idx++] = arr2[i2++];
    print(arr, l, r);
}

void mergeSort(int arr[], int l, int r) {
    cout << "Calling merge sort for : " << l << " to " << r << "\n";
    if(l>=r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main() {
    int arr[10] = {1,5,3,6,4,9,8,10,7,2};
    mergeSort(arr,0,9);
    cout << "=========================================================\nFinal sorted array : \n";
    print(arr,0,9);
}
