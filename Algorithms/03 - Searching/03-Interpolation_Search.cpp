#include <bits/stdc++.h>
using namespace std;

static int bin_count = 0, interpol_count=0;

int Binary_Search(int arr[], int low, int high, int num) {
    bin_count++;
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

int Interpolation_Search(int arr[], int low, int high, int num) {
    interpol_count++;
    if(low>=high) {
        if(arr[low]==num)
            return low;
        return -1;
    }
    else {
        int pos = low + ((num - arr[low]) * (high - low))/(arr[high]-arr[low]);
        if(arr[pos] == num)
            return pos;
        else if(arr[pos] > num)
            return Interpolation_Search(arr, low, pos-1, num);
        else
            return Interpolation_Search(arr, low+1, high, num);
    }
}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,9,10};
    cout << "UNIFORMLY DISTIBUTED DATASET\n====================================\n";
    Interpolation_Search(arr, 0, 8, 9);
    cout << "Number of iterations required by Interpolation Search : " << interpol_count << "\n";
    Binary_Search(arr, 0, 8, 9);
    cout << "Number of iterations required by Binary Search : " << bin_count << "\n";
    int arr1[10] = {1,1,1,2,2,2,2,9,1000};
    interpol_count = 0, bin_count = 0;
    cout << "\n\nNON-UNIFORMLY DISTIBUTED DATASET\n====================================\n";
    Interpolation_Search(arr1, 0, 8, 9);
    cout << "Number of iterations required by Interpolation Search : " << interpol_count << "\n";
    Binary_Search(arr1, 0, 8, 9);
    cout << "Number of iterations required by Binary Search : " << bin_count << "\n";
}
