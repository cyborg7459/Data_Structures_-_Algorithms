// Problem : You are given an array of binary strings strs and two integers m and n. Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
// Explanation : The wordings of the problem are like, find the maximum of something that can be obtained under the contstraint that something else does not exceed a particular value. Hence clearly,
// this problem, as well as other problems with similar wording, has an implementation like Knapsack

#include <bits/stdc++.h>
using namespace std;

int findMaxForm(vector<string>& strs, int m, int n) {
    int arr[m+1][n+1];
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            arr[i][j] = 0;
        }
    }

    int ans = 0;
    for(string str : strs) {
        int z = count(str.begin(), str.end(), '0');
        int o = count(str.begin(), str.end(), '1');

        for(int i=m; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                if(i+z<=m && j+o<=n) arr[i+z][j+o] = max(arr[i+z][j+o], 1+arr[i][j]);
            }
        }
    }

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            ans = max(ans, arr[i][j]);
        }
    }

    return ans;
}

int main() {
	vector <string> v = {"10","0","1"};
	cout << findMaxForm(v, 1, 1) << endl;
}
