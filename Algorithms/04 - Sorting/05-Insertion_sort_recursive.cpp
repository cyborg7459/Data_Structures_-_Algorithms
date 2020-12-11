#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";
}

void insertion_sort_rec(int arr[], int n) {
    cout << "Function called\n";
    if(n <= 1)
        return;
    insertion_sort_rec(arr, n-1);
    int cur = n-1;
    while(cur > 0 && arr[cur] < arr[cur-1]) {
        swap(arr[cur], arr[cur-1]);
        cur--;
    }
}

int main() {
    int arr[10] = {9,7,6,15,17,5,10,11,2,4};
    insertion_sort_rec(arr,10);
    print(arr,10);
}
