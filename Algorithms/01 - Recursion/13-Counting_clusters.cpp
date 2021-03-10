#include <bits/stdc++.h>
using namespace std;

void func(int x, int y, int arr[5][5]) {
    if(x>4 || y>4 || x<0 || y<0) return;
    if(arr[x][y] == 0) return;
    arr[x][y] = 0;
    func(x+1, y, arr);
    func(x-1, y, arr);
    func(x, y-1, arr);
    func(x, y+1, arr);
    func(x+1, y+1, arr);
    func(x-1, y+1, arr);
    func(x+1, y-1, arr);
    func(x-1, y-1, arr);
}

int main() {
    int arr[5][5] = {{1,0,0,1,0}
                    ,{0,1,0,1,0}
                    ,{0,0,0,0,1}
                    ,{0,1,0,0,0}
                    ,{1,0,0,0,0}};
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
