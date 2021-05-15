// PS : Imagine a bar graph with bars of given heights (arr), and width equal to 1. Find the area of the largest rectangle which can be formed by staying within the limits of the bars in O(n)

// Solution : In a group of bars, the biggest rectangle that can be formed is equal to the height of the shortest bar * total width. Thus, we need to find the areas for all groups of conseutive
// bars possible and then return the largest area possible. However, by brute force, it would take O(n^2). Thus, what we can do is that for each bar, calculate the area of the rectangle formed
// when that bar is the shortest in group. For that we just need to find the next smallest bar before and after that bar, which can be found easily using a stack and 2 different loops.
// One very important point in this question is that we cannot declare r and l inside of the function call as it would lean to segmentation fault for large values of 'n' due to too much memory
// allocation withing a function stack. Hence, define them in global scope where no such memory isssue will occur.

#include <bits/stdc++.h>
using namespace std;

#define print(x) {for(auto t : x)\
				cout << t << " ";\
				cout << "\n";}
#define INF 1000000007

int r[1000000] = {};
int l[1000000] = {};

long long getMaxArea(long long arr[], int n) {
	stack<pair<long long, int>> st;
	for(int i=0; i<n; i++) {
		long long t = arr[i];
		if(st.empty() || st.top().first <= t)
			st.push({t, i});
		else {
			while(!st.empty() && st.top().first > t) {
				r[st.top().second] = i;
				st.pop();
			}
			st.push({t, i});
		}
	}
	while(!st.empty()) {
		r[st.top().second] = n;
		st.pop();
	}
	for(int i=n-1; i>=0; i--) {
		long long t = arr[i];
		if(st.empty() || st.top().first <= t)
			st.push({t, i});
		else {
			while(!st.empty() && st.top().first > t) {
				l[st.top().second] = i;
				st.pop();
			}
			st.push({t,i});
		}
	}
	while(!st.empty()) {
		l[st.top().second] = -1;
		st.pop();
	}
	long long ans = 0;
	for(int i = 0; i<n; i++) {
		long long h = arr[i];
		int w = r[i] - l[i] - 1;
		long long area = h*w;
		ans = max(ans, area);
	}
	return ans;
}

int main() {
	long long arr[10] = {1, 1, 1, 1 , 1 , 1, 1, 1, 0 ,1};
	cout << getMaxArea(arr, 10) << endl;
}
