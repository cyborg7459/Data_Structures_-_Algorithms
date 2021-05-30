// IMPLEMENTATION LOGIC
// First constraint is that there can be only one queen in each row, and hence the N_Queens function takes in 2 parameters, where cur stores the current ongoing row and n shows the total number of rows. Thus,
// if cur exceeds n, then it means that a complete arrangement has been found. Now, we keep 3 arrays, one for columns, and 2 for the 2 kinds of diagonals, where the value 0/1 indicates the presence of a queen
// in that column or diagonal. Now for each row, we'll iterate through all columns. Then we'll check for the given cell whether it is free from attack or not. If it's not free, then we simply move to the next
// columns. If free, then the first thing we do is to place the queen in that cell. By placing, we mean putting the values 1 in that cell's column and diagonals, and after that proceeding to the next row. One
// the way back, we again free that cell and move the queen to the next cell, to check for more solutions.

#include <bits/stdc++.h>
using namespace std;

int column[100] = {};
int diag1[200] = {};
int diag2[200] = {};
int board[100] = {};
int ans = 0;
int N;

bool isSafe(int row_num, int col_num) {
    if(column[col_num] == 1) return false;
    if(diag1[row_num + col_num] == 1) return false;
    if(diag2[N-(row_num - col_num)] == 1) return false;
    return true;
}

void print_board() {
    cout << "Possible arrangement :-\n";
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(j == board[i])
                cout << "Q ";
            else
                cout << "* ";
        }
        cout << "\n";
    }
    cout << "\n\n";
}

void N_Queens(int cur, int n) {
    if(cur == n+1) {
        ans++;
        print_board();
    }
    else {
        for(int i=1; i<=n; i++) {
            if(isSafe(cur, i)) {
                board[cur] = i;
                column[i] = 1;
                diag1[cur+i] = 1;
                diag2[N - (cur-i)] = 1;
                N_Queens(cur+1, n);
                column[i] = 0;
                diag1[cur+i] = 0;
                diag2[N - (cur-i)] = 0;
            }
            else continue;
        }
    }
}

void solve() {
    cout << "Enter size of chessboard : ";
    cin >> N;
    N_Queens(1, N);
    cout << "Total number of possible arrangements : " << ans << "\n";
}

signed main()
{
    int q = 1;
    while(q--)
        solve();
}
