// PS : Given an array of heights, we can either increase a height by 'k' or decrease it by 'k' (we can't decrease it by k if the height is currently less that k). We have to perform either of the
// 2 operations exactly one time for each of the buildings. Out goal is to caluclate the minimum possible height difference between the tallest and shortest buildings after all operations are
// completed

// Explanation : First we create a sorted vector which stores all possible heights that can be acheved, along with the index of the building which can give that height (hence, we'll use a pair). Then, we'll
// use sliding window technique in such a way that at all times the window contains each building at least once. We can achieve this by keeping track of the buildings using an additional visited array.
// For each such window which contains all buildings, we'll check for the difference of heights b/w the tallest and the shortest and update ans accordingly. Then we'll remove the building from the start.
// If doing this removes all occurrences of any particular building, then we start adding from the front until once again all buildings are present in the sliding window.

#include <bits/stdc++.h>
using namespace std;

int main() {
	int k = 5, n = 10;
	int arr[n] = {2,6,3,4,7,2,10,3,2,1};
	vector<pair<int, int>> v;
	int visited[n] = {};
	int cnt = 0;
	for(int i = 0; i<n; i++) {
		v.push_back({arr[i]+k, i});
		if(arr[i] - k >= 0)
			v.push_back({arr[i]-k, i});
	}
	int start = 0, end = 0;
	sort(v.begin(), v.end());
	while(true) {
		visited[v[end].second]++;
		if(visited[v[end].second] == 1)
			cnt++;
		if(cnt == n) break;
		end++;
	}
	int ans = v[end].first - v[start].first;
	while(end < v.size()) {
		if(cnt == n) {
			ans = min(ans, v[end].first - v[start].first);
			visited[v[start].second]--;
			if(visited[v[start].second] == 0)
				cnt--;
			start++;
		}
		else if(cnt < n) {
			end++;
			if(end >= v.size()) break;
			visited[v[end].second]++;
			if(visited[v[end].second] == 1) cnt++;
		}
	}
	cout << ans;
}
