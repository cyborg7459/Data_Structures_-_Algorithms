#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void rearrange(int arr[], int end) {
    int start = 0;
    end--;
    while(start < end) {
        if(arr[start]!=0)
            start++;
        if(arr[end]==0)
            end--;
        if(arr[start]==0 && arr[end]!=0) {
            swap(arr[start], arr[end]);
            end--;
            start++;
        }
    }
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    rearrange(arr,8);
    print(arr,8);
}
