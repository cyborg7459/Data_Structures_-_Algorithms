// PS : To rotate a square matrix anti-clockwise by 90 degrees without using extra space
// Explanation : This can be achieved by 2 steps - First invert the matrix along the diagonal (see the indexes of elements to interchange and you'll notice a pattern). Once this is done, take the mirror
// image of the matrix (about a vertical mirror)

#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            int sumi = i + j;
            int add = n - sumi - 1;
            int i1 = i + add, j1 = j + add;
            int temp = matrix[i1][j1];
            matrix[i1][j1] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
    int l = 0, r = n-1;
    while(l < r) {
        for(int row = 0; row < n; row++) {
            int temp = matrix[row][l];
            matrix[row][l] = matrix[row][r];
            matrix[row][r] = temp;
        }
        l++;
        r--;
    }
}

int main() {
    int n;
    cin>>n;
    vector<vector<int> > matrix(n);
    for(int i=0; i<n; i++) {
        matrix[i].resize(n);
        for(int j=0; j<n; j++)
            cin>>matrix[i][j];
    }
    rotate(matrix);
    for (int i = 0; i < n; ++i) {
        for(int j=0; j<n; j++)
            cout<<matrix[i][j]<<" ";
        cout<<"\n";
    }
}
