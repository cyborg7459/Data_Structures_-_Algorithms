#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";
}

void bubble_sort_rec(int arr[], int n) {
    cout << "BUBBLE SORT RECURSIVE CALLED !!\n";
    if(n==1)
        return;
    else {
        for(int i=0; i<n; i++) {
            if(arr[i] > arr[i+1])
                swap(arr[i], arr[i+1]);
        }
    }
    bubble_sort_rec(arr, n-1);
}

int main() {
    int arr[10] = {5,4,93,9,54,285,3,5,7,56};
    bubble_sort_rec(arr,10);
    print(arr,10);
}
