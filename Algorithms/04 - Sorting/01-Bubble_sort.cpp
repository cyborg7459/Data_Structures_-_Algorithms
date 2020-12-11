#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";
}

void bubble_sort(int arr[], int n) {
    for(int i=0; i<n; i++) {
        for(int j = i+1; j < n; j++) {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

int main() {
    int arr[10] = {5,4,93,9,54,285,3,5,7,56};
    bubble_sort(arr,10);
    print(arr,10);
}
