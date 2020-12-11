#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";
}

void selection_sort(int arr[], int n) {
    cout << "SELECTION SORT\n";
    int start = 0, temp, min;
    while(start < n) {
        min = arr[start];
        temp = start;
        for(int i = start; i < n; i++) {
            if(arr[i] < min) {
                min = arr[i];
                temp = i;
            }
        }
        if(temp!=start)
            swap(arr[start], arr[temp]);
        start++;
    }
}

int main() {
    int arr[10] = {5,4,93,9,54,285,3,5,7,56};
    selection_sort(arr,10);
    print(arr,10);
}
