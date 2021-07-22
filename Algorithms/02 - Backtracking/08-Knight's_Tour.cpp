// PS : We have to move the Knight in a chessboard in such a manner that it covers each and every box on the board without going on the same board twice
// Explanation : Backtracking solution. We'll start with the first move at the first box, from there on, we'll go to the next possible box which is valid and recursively do this.
// If we reach the end without breaking, it means that the current solution was correct. If however, we reach a point where we can't get any valid points, then that particular solution
// is wrong and we need to backtrack from there. Hence, we'll mark that box as unvisited and move back one step. From there, we can move to the next valid box. The order of directions in the
// dir vector is also important for runtime, and this partiuclar order can solve till n=8. If we change it, then n=8 would give TLE. This one is efficient because we know that from the point
// we're starting, we'll often have to move down and right, and hence accordingly we choose the directions

#include <bits/stdc++.h>
using namespace std;

const int N = 8;
int grid[N][N];

vector<pair<int, int>> dir = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
bool isValid(int i, int j) {
	return (i >=0 && i<N && j >=0 && j<N && grid[i][j] == -1);
}
int num_of_digits(int n) {
	int cnt = 1;
	n/=10;
	while(n > 0) {
		n/=10;
		cnt++;
	}
	return cnt;
}

void print_grid() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
            if(num_of_digits(grid[i][j]) == 1) cout << "0";
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

bool KnightTour(int cur_i, int cur_j, int cur_move) {
	if(cur_move == N*N-1) {
		grid[cur_i][cur_j] = cur_move;
		return true;
	}
	grid[cur_i][cur_j] = cur_move;
	for(int i=0; i<8; i++) {
        pair<int,int> p = dir[i];
		int x = cur_i + p.first;
		int y = cur_j + p.second;
		if(isValid(x, y)) {
			if(KnightTour(x, y, cur_move + 1)) return true;
		}
	}
    grid[cur_i][cur_j] = -1;
	return false;
}

int main() {
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			grid[i][j] = -1;
		}
	}
	if(KnightTour(0, 0, 0))
	   print_grid();
    else
        cout << "No solution exists";
}
