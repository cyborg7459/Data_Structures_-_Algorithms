// The following algorithm can be used to perform searching in a rotated sorted array in O(log n) complexity
// Explanation : The first step in this solution is to find the pivot element, i.e. the point w.r.t. which the array has been rotated. This can be done by binary search, i.e.
// each time we'll check whether the middle element is the pivot or not. If yes, then simply return the mid element. Otherwise, we'll check whether the pivot lies towards the
// left or right of the mid element and accordingly narrow our search

#include <iostream>
using namespace std;

int binary_search(int arr[], int low, int high, int key) {
    if(high < low)
        return -1;
    int mid = (high+low)/2;
    if(arr[mid]==key)
        return mid;
    if(arr[mid] > key)
        return binary_search(arr, low, mid-1, key);
    return binary_search(arr, mid+1, high, key);
}

int find_pivot(int arr[], int low, int high) {
    if(high < low)
        return -1;
    if(high == low)
        return low;
    int mid = (high+low)/2;
    if(mid < high && arr[mid+1]<arr[mid])
        return mid;
    if(mid > low && arr[mid] < arr[mid-1])
        return mid-1;
    if(arr[low] >= arr[mid])
        return find_pivot(arr, low, mid-1);
    return find_pivot(arr, mid+1, high);
}

int find_by_binary(int arr[], int n, int key) {
    int pivot = find_pivot(arr, 0, n-1);
    if(pivot == -1)
        return binary_search(arr, 0, n-1, key);
    if(arr[pivot] == key)
        return pivot;
    if(arr[0]<= key)
        return binary_search(arr, 0, pivot-1, key);
    return binary_search(arr, pivot+1, n-1, key);
}

int main() {
    int arr[] = {4,5,6,7,8,9,10,1,2,3};
    cout << find_by_binary(arr, 10, 3);
}
