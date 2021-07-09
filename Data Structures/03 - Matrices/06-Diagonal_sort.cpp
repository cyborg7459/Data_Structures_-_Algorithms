#include <bits/stdc++.h>
using namespace std;

void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
    int start_row = 1;
    while(start_row < n) {
        vector<int> v;
        int x = start_row, y = 0;
        while(x < n && y < m) {
            v.push_back(matrix[x][y]);
            x++;
            y++;
        }
        sort(v.begin(), v.end());
        x = start_row, y = 0;
        int idx = 0;
        while(idx < v.size()) {
            matrix[x][y] = v[idx];
            x++;
            y++;
            idx++;
        }
        start_row++;
    }
    int start_col = 1;
    while(start_col < m) {
        vector<int> v;
        int x = 0, y = start_col;
        while(x < n && y < m) {
            v.push_back(matrix[x][y]);
            x++;
            y++;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        x = 0, y = start_col;
        int idx = 0;
        while(idx < v.size()) {
            matrix[x][y] = v[idx];
            x++;
            y++;
            idx++;
        }
        start_col++;
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    int inputline2[n*m];
    for (int i = 0; i < n*m; ++i)
        cin>> inputline2[i];
    vector<vector<int> > matrix( n , vector<int> (m, 0));
    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] = inputline2[i * m + j];
        }
    }
    diagonalSort(matrix, n, m);
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
