// PS : Given a grid of oranges, where the numbers 0, 1, and 2 represent no orange, fresh orange and rotten orange respectively. A rotten orange can cause an orange next to it (sharing a side, not a corner)
// rot in 1 second. Our goal is to find out at what time each orange rots and return the time taken for all oranges to rot (-1 if some oranges never rot);

// Explanation : Here we see that the rotting of one orange at a given second sets up a chain of actions and it then rots other fresh oranges next to it, and then they do the same. Hence, this is a clear
// question of using BFS/DFS. In the given solution, depth first search is used. For every orange that rots, we then recursively call it's adjacent oranges while incrementing the time by 1. However, 2
// oranges will contnue to recursively call each other unless some break is there. Hence in this problem, the cases to break the recursion are quite important. We have to break the recursion in any of the
// given scenarios :-
// 1) If the point goes out of bounds of the array (hence the isValid function)
// 2) If the point does not contain any orange (i.e. grid[i][j] = 0)
// 3) If the orange on the given point has rotten at the time earlier than the current time (for oranges that rot after the current time means that we already reached that poisition through some other path
// but that path was not the shortest optimum path, and the current path is shorter than that). Here's one caveat that the value of 1 would be smallest each time but a value of 1 does not mean that the orange
// had rotted at t = 1sec, thus handled it accordingly and not broke the recursion.
// Since the values 0,1,2 are already taken, we start from t = 3 sec as an equivalent of t = 1 sec and at the end subtract the time by 2 for each point


#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1,0}, {0,-1}, {0, 1}, {-1, 0}};

bool isValid(int x, int y, int n, int m) {
	return (x >= 0 && x < n && y>=0 && y<m);
}

void func(vector<vector<int>> &grid, int k, int i, int j, int n, int m) {
    if(!(isValid(i, j, n, m) && grid[i][j] != 0)) return;
	if(grid[i][j] != 1 && grid[i][j] <= k) return;
	else {
		grid[i][j] = k;
		for(pair<int, int> p : dir)
			func(grid, k+1, i+p.first, j+p.second, n, m);
	}
	return;
}

int orangesRotting(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j] == 2) {
				for(pair<int, int> p : dir)
					func(grid, 3, i+p.first, j+p.second, n, m);
			}
		}
	}

	int mx = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(grid[i][j] == 1) return -1;
			if(grid[i][j] != 0 && grid[i][j] != 2)
				mx = max(mx, grid[i][j]);
		}
	}

	return mx - 2;
}

int main() {
	vector<vector<int>> grid = {{1,1,0,1},{1,1,0,1},{1,1,0,1},{2,1,1,0}};
	int x = orangesRotting(grid);
    for(int i=0; i<grid.size(); i++) {
        for(int t : grid[i]) {
            if(t == 0)
                cout << "* ";
            else cout << t-2 << " ";
        }
        cout << "\n";
    }
	cout << x;
}
