#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}

void rearrange(int arr[], int end) {
  int zi = -1;
  for(int i=0; i<end; i++) {
    if(arr[i] != 0) {
      zi++;
      swap(arr[i], arr[zi]);
    }
  }
}

int main() {
    int arr[] = {1, 2, 0, 4, 3, 0, 5, 0};
    rearrange(arr,8);
    print(arr,8);
}
