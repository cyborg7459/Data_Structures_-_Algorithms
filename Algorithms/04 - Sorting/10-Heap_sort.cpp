// Explanation : The first step of this algorithm is to create a max heap from the given array. For this, apply heapify on the first half of the array (only the first half because all the elements in the
// later half of the array are leaf nodes and have no children). Once this is done, then one by one take the first element from the array and swap it with the last available element, hence sorting the array
// from behind (as the first element would be the maxumum of the remaining heap). After swapping, apply heapify on the remaining array to make sure that again the largest remaining element is at the top

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    int idx = i;
    int l = 2*idx + 1;
    int r = 2*idx + 2;
    if(l < n && arr[l] > arr[idx]) idx = l;
    if(r < n && arr[r] > arr[idx]) idx = r;
    if(idx != i) {
        swap(arr[i], arr[idx]);
        heapify(arr, n, idx);
    }
}

void buildHeap(int arr[], int n) {
    for(int i=n/2-1; i>=0; i--) heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for(int i=n-1; i>=0; i--) {
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

int main() {
    int n = 10;
    int arr[n] = {10,9,8,7,6,5,4,3,2,1};
    heapSort(arr, n);
    for(int i=0; i<n; i++) cout << arr[i] << " ";
}
