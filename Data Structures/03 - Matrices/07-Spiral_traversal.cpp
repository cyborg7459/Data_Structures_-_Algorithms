#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c) {
	bool hor = true, ver = true, b = true;
	int ru = -1, rd = r, cr = c, cl = -1;
	int endx = r/2, endy = c/2;
	vector<int> res;
	while(true) {
		res.push_back(matrix[x][y]);
		if(res.size() == r*c) break;
		if(b) {
			if(hor) {
				y++;
				if(y == cr) {
					y--;
					ru = x;
					x++;
					b = !b;
					hor = !hor;
				}
			}
			else {
				y--;
				if(y == cl) {
					y++;
					rd = x;
					x--;
					b = !b;
					hor = !hor;
				}
			}
		}
		else {
			if(ver) {
				x++;
				if(x == rd) {
					x--;
					cr = y;
					y--;
					b = !b;
					ver = !ver;
				}
			}
			else {
				x--;
				if(x == ru) {
					x++;
					cl = y;
					y++;
					b = !b;
					ver = !ver;
				}
			}
		}
	}
	return res;
}

int main() {
	vector<vector<int>> matrix = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};
	vector<int> v = spirallyTraverse(matrix, 4, 4);
	for(int t : v) cout << t << " ";
	cout << endl;
}
