#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int l, int r) {
    for(int i=l; i<=r; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l, j = r-1;
    while(i <= j) {
        if(arr[i] <= pivot)
            i++;
        else if(arr[j] >= pivot)
            j--;
        else if(arr[i] > pivot && arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    swap(arr[i], arr[r]);
    return i;
}

void quickSort(int arr[], int l, int r) {
    if(l>=r)
        return;
    int pi = partition(arr, l, r);
    quickSort(arr, l, pi-1);
    quickSort(arr, pi+1, r);
}

int main() {
    int arr[10] = {122,142,31,618,182,1,98,67,8,17};
    quickSort(arr, 0, 9);
    print(arr, 0, 9);
}
