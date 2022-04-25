// Problem: https://leetcode.com/problems/set-matrix-zeroes/
// Solution: To do the given problem in O(1) space complexity, all we need to do is have the first element of each row and column to be the marker as to whether we have to zero out the entire
// row or column. However, this might lead to problem in case zeroes are present in the first row/column itself, because in that case zeroing out the entire first row due to a single 0 in it
// would mean that now when we do the operation for columns, it would appear that all columns must be made 0. Hence, for this, we'll operate on the first row and columns separately using a
// different variable, and use the algorithm to zero out the rest of rows and colums

#include <bits/stdc++.h>
using namespace std;

void print_matrix(vector<vector<int>> &v) {
  int r = v.size(), c = v[0].size();
  for(int i=0; i<r; i++) {
    for(int j=0; j<c; j++) {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
}

void setZeroes(vector<vector<int>>& matrix) {
    bool fr=false, fc = false;
    int r = matrix.size(), c = matrix[0].size();
    for(int i=0; i<r; i++) {
        for(int j=0; j<c; j++) {
            if(matrix[i][j]==0) {
                if(i==0) fr = true;
                if(j==0) fc = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i=1; i<r; i++) {
        if(matrix[i][0] == 0) for(int j=0; j<c; j++) matrix[i][j] = 0;
    }
    for(int j=1; j<c; j++) {
        if(matrix[0][j] == 0) for(int i=0; i<r; i++) matrix[i][j] = 0;
    }
    if(fr) for(int j=0; j<c; j++) matrix[0][j] = 0;
    if(fc) for(int i=0; i<r; i++) matrix[i][0] = 0;
}

int main() {
  vector<vector<int>> matrix = {
    {0, 1, 2, 0},
    {3, 4, 5, 2},
    {1, 3, 1, 5}
  };
  setZeroes(matrix);
  print_matrix(matrix);
}
