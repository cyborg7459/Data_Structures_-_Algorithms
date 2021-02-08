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
                cout << "Q";
            else
                cout << "_";
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
