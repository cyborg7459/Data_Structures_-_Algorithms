#include <bits/stdc++.h>
using namespace std;

long long gridTraveller(int n, int m, vector<vector<int>> &visited, vector<vector<int>> &arr) {
    if(n==0 || m==0) return 0;
    if(n==1 && m==1) return 1;
    if(visited[n][m] == 1) return arr[n][m];
    long long x = gridTraveller(n-1, m, visited, arr);
    long long y = gridTraveller(n, m-1, visited, arr);
    visited[n][m] = 1;
    arr[n][m] = x+y;
    return x+y;
}

int main() {
    int n, m;
    cout << "Enter number of rows : ";
    cin >> n;
    cout << "Enter number of columns : ";
    cin >> m;
    vector<vector<int>> visited, arr;
    for(int i=0; i<=n; i++) {
        vector<int> temp;
        for(int j=0; j<=m; j++) {
            temp.push_back(0);
        }
        visited.push_back(temp);
        arr.push_back(temp);
    }
    cout << gridTraveller(n,m,visited, arr);
}
