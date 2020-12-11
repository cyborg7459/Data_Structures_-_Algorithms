#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n){
    for(int i=0; i<10; i++)
        cout << arr[i] << " ";
}

void insertion_sort(int arr[], int n) {
    int cur = 1, temp;
    while(cur < n) {
        if(arr[cur] < arr[cur-1]) {
            temp = cur;
            while(arr[temp] < arr[temp-1]) {
                swap(arr[temp], arr[temp-1]);
                temp--;
                if(temp == 0)
                    break;
            }
        }
        cur++;
    }
}

int main() {
    int arr[10] = {5,4,93,9,54,285,3,5,7,56};
    insertion_sort(arr,10);
    print(arr,10);
}
