#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int l, int r) {
    for(int i=l; i<=r; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void merge(int arr[],int l,int r) {
    cout << "Calling merge funcion for " << l << " to " << r << "\nThe array section after merging is : ";
    int n1 = (r-l)/2+1;
    int n2 = (r-l+1)-n1;
    int arr1[n1], arr2[n2];
    for(int i=l, j=0; i<l+n1; i++, j++)
        arr1[j] = arr[i];
    for(int i=l+n1, j=0; i<=r; i++, j++)
        arr2[j] = arr[i];
    int i=0, j=0, idx=l;
    while(i<n1 && j<n2) {
        if(arr1[i]<arr2[j]) {
            arr[idx] = arr1[i];
            i++;
            idx++;
        }
        else {
            arr[idx] = arr2[j];
            j++;
            idx++;
        }
    }
    while(i<n1) {
        arr[idx] = arr1[i];
        i++;
        idx++;
    }
    while(j<n2) {
        arr[idx] = arr2[j];
        j++;
        idx++;
    }
    print(arr, l, r);
}

void mergeSort(int arr[], int l, int r) {
    cout << "Calling merge sort for : " << l << " to " << r << "\n";
    if(l>=r)
        return;
    mergeSort(arr, l, (r+l)/2);
    mergeSort(arr, (r+l)/2+1, r);
    merge(arr, l, r);
}

int main() {
    int arr[10] = {1,5,3,6,9,4,8,10,7,2};
    mergeSort(arr,0,9);
    cout << "=========================================================\nFinal sorted array : \n";
    print(arr,0,9);
}
