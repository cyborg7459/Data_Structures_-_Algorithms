// PS : Solving a given sudoku, or otherwise printing no solution possible
// Explanation : The solution to this problem is similar to solving n-queens problem. We keep a track of all the numbers that are present in a current row, in current column as well
// as the current box. Then we check all possible numbers for each empty box. If a number is valid, then for that moment, we keep the number over there and move forward. If later
// some problem occurs, then we back-track and check for other numbers. If we reach the end, however, it means that we've solved the sudoku

#include <bits/stdc++.h>
using namespace std;
#define UNASSIGNED 0

#define N 9

vector<int> row[9];
vector<int> col[9];
vector<int> box[3][3];

bool isValid(int i, int j, int num) {
    if(find(row[i].begin(), row[i].end(), num) != row[i].end()) return false;
    if(find(col[j].begin(), col[j].end(), num) != col[j].end()) return false;
    if(find(box[i/3][j/3].begin(), box[i/3][j/3].end(), num) != box[i/3][j/3].end()) return false;
    return true;
}

bool sudoku(int i, int j, int grid[N][N]) {
    if(i == 9) return true;
    if(grid[i][j] != 0) {
        int x = i, y = j+1;
        if(y == 9) {
            x++;
            y = 0;
        }
        return sudoku(x, y, grid);
    }
    for(int num = 1; num < 10; num++) {
        if(isValid(i, j, num)) {
            grid[i][j] = num;
            row[i].push_back(num);
            col[j].push_back(num);
            box[i/3][j/3].push_back(num);
            int x = i, y = j+1;
            if(y == 9) {
                x++;
                y = 0;
            }
            if(sudoku(x, y, grid)) return true;
            row[i].pop_back();
            col[j].pop_back();
            box[i/3][j/3].pop_back();
			grid[i][j] = 0;
        }
    }
    return false;
}

bool SolveSudoku(int grid[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(grid[i][j] > 0) {
                int t = grid[i][j];
                row[i].push_back(t);
                col[j].push_back(t);
                box[i/3][j/3].push_back(t);
            }
        }
    }
	return sudoku(0,0,grid);
}

void printGrid (int grid[N][N]) {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
	int grid[N][N];
	for(int i=0;i<9;i++)
	    for(int j=0;j<9;j++)
	        cin>>grid[i][j];
	if (SolveSudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No solution";
    cout<<endl;
	return 0;
}
