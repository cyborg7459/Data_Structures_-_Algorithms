#include <iostream>
using namespace std;

// =============================================================================================================================================================================================

// First algorithm is to one by one shift the elements for 'd' number of times. This method does not take up any extra space but it's time complexity is O(d*n)
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

// ===============================================================================================================================================================================================

// Second algorithm rotates the array in O(n) time but it has a space complexity of O(n) as well as it uses a temporary array
void rotate_array(int arr[], int d, int n) {
    d = d % n;
    int temp[n];
    for(int i=0; i<n; i++) {
        int idx = i-d;
        if(idx < 0)
            idx+=n;
        temp[idx] = arr[i];
    }
    for(int i=0; i<n; i++)
        arr[i] = temp[i];
}

// ===============================================================================================================================================================================================

// Reversal algorithm for rotating array does the job in O(n) time without using any temporary array, i.e. O(1) space complexity. What it does is that it takes the array and divides it into
// 2 parts, first d elements in one subarray and remaining in other, then both these subarrays are reversed, and finally the complete array is reversed once again
// Thus if we have [1,2,3,4,5,6,7,8] and d = 3, then
// STEP 1 : [3,2,1,4,5,6,7,8]
// STEP 2 : [3,2,1,8,7,6,5,4]
// STEP 3 : [4,5,6,7,8,1,2,3]
// This is the desired result
void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void reversal_Rotate(int arr[], int d, int n) {
    d = d%n;
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr, 0, n-1);
}

// ===============================================================================================================================================================================================


void  printArr(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    for(int i=0; i<10; i++) {
        reversal_Rotate(arr, 1, 10);
        printArr(arr, 10);
    }
}
