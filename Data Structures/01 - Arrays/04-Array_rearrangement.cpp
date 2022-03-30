// Given an array of elements of length N, ranging from 0 to N – 1. All elements may not be present in the array. If element is not present then there will be -1 present in the array.
// Rearrange the array such that A[i] = i and if i is not present, display -1 at that place.
// EXPLANATION: In the given problem, we'll start with traversing the array. If there is the correct or no element at a position, then we'll just proceed forward. Else if the position
// is occupied by the incorrect number, we'll swap the number with it's correct position and repeat the step for the current position

#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void func(int arr[],int i) {
    if(arr[i] == i || arr[i]==-1)
        return;
    else {
        int y = arr[i];
        swap(arr[i], arr[y]);
        func(arr, i);
    }
}

void rearrange(int arr[], int n) {
    for(int i=0; i<n; i++) {
        func(arr, i);
    }
}



int main() {
    int arr[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    rearrange(arr,10);
    print(arr,10);
}
