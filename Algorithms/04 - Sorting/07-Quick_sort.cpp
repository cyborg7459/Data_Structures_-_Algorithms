#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int l, int r) {
    for(int i=l; i<=r; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

int partition(int arr[], int l, int r) {
    int el = arr[r], count=0;
    for(int i=l; i<=r; i++) {
        if(arr[i] < el)
            count++;
    }
    int idx = l+count;
    int temp[r-l+1];
    temp[count] = el;
    int i=0, j=0;
    for(int k=l; k<=r; k++) {
        if(arr[k]<el) {
            temp[i] = arr[k];
            i++;
        }
        else {
            temp[count+j+1] = arr[k];
            j++;
        }
    }
    for(int i=0; i<=r-l; i++) {
        arr[l+i] = temp[i];
    }
    return idx;
}

void quickSort(int arr[], int l, int r) {
    if(l>=r)
        return;
    int pi = partition(arr, l, r);
    quickSort(arr, l, pi-1);
    quickSort(arr, pi+1, r);
}

int main() {
    int arr[10] = {1,5,2,8,1,4,9,2,6,2};
    quickSort(arr, 0, 9);
    print(arr, 0, 9);
}
