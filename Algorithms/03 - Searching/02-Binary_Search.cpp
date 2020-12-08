#include <bits/stdc++.h>
using namespace std;

int Binary_Search(int arr[], int low, int high, int num) {
    if(low > high)
        return -1;
    else {
        int mid = (low+high)/2;
        if(arr[mid] == num)
            return mid;
        else if(arr[mid]>num)
            return Binary_Search(arr, low, mid-1, num);
        else
            return Binary_Search(arr, mid+1, high, num);
    }
}

int main() {
    int arr[10] = {1,2,4,5,6,7,8,9,10};
    cout << Binary_Search(arr, 0, 8, 0) << "\n";
    cout << Binary_Search(arr, 0, 8, 1) << "\n";
    cout << Binary_Search(arr, 0, 8, 2) << "\n";
    cout << Binary_Search(arr, 0, 8, 3) << "\n";
    cout << Binary_Search(arr, 0, 8, 4) << "\n";
    cout << Binary_Search(arr, 0, 8, 5) << "\n";
    cout << Binary_Search(arr, 0, 8, 6) << "\n";
    cout << Binary_Search(arr, 0, 8, 7) << "\n";
    cout << Binary_Search(arr, 0, 8, 8) << "\n";
    cout << Binary_Search(arr, 0, 8, 9) << "\n";
    cout << Binary_Search(arr, 0, 8, 10) << "\n";
    cout << Binary_Search(arr, 0, 8, 11) << "\n";
}
