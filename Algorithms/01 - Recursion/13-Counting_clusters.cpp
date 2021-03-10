#include <bits/stdc++.h>
using namespace std;

void func(int x, int y, int arr[5][5]) {
    arr[x][y] = 0;
    if(x+1 < 5 && arr[x+1][y] == 1)
        func(x+1, y, arr);
    if(x-1 >= 0 && arr[x-1][y] == 1)
        func(x-1, y, arr);
    if(y-1 >= 0 && arr[x][y-1] == 1)
        func(x, y-1, arr);
    if(y+1 < 5 && arr[x][y+1] == 1)
        func(x, y+1, arr);
}

int main() {
    int arr[5][5] = {{1,1,0,0,1}
                    ,{0,0,0,0,1}
                    ,{0,0,1,0,0}
                    ,{1,0,0,0,1}
                    ,{0,0,1,1,0}};
    int counter = 0;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(arr[i][j] == 1) {
                counter++;
                func(i, j, arr);
            }
        }
    }
    cout << "The number of clusters is : " << counter << "\n";
}
