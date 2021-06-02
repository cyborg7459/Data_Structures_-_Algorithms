// PS : https://practice.geeksforgeeks.org/problems/flood-fill-algorithm1856/1/?track=md-recursion&batchId=144
// Explanation : Normal dfs solution, however one small thing to keep in mind is that it is possible that the new Color is same as final color. Hence we needed to have the breaking condition
// (v[i][j] == cf || v[i][j]!=ci) and not just (v[i][j]!=ci) because in case ci and cf are equal, the second condition would never terminate and we'd be stuck in an infinite recursion

#include<bits/stdc++.h>
using namespace std;

pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void func(vector<vector<int>> &v, int i, int j, int ci, int cf, int r, int c) {
    if(i<0 || i>=r || j<0 || j>=c) return;
    if(v[i][j] == cf || v[i][j]!=ci) return;
    v[i][j] = cf;
    for(pair<int, int> p : dir)
        func(v, i+p.first, j+p.second, ci, cf, r, c);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    int r = image.size();
    int c = image[0].size();
    func(image, sr, sc, image[sr][sc], newColor, r, c);
    return image;
}

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>>image(n, vector<int>(m,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			cin >> image[i][j];
	}
	int sr, sc, newColor;
	cin >> sr >> sc >> newColor;
	vector<vector<int>> ans = floodFill(image, sr, sc, newColor);
	for(auto i: ans) {
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	return 0;
}
