// Explanation : The brute force algorithm for this problem is O(n^6). However, we can use 2-D extenstion of Kadane's algorithm to reduce it to O(n^3). What we do is that for each pair of columns
// i and j, we calculate the sum of elements from column i to column j for each row (use a prefix sum matrix to do this in O(1)). Hence, we get the array for sums for a given width. Now, we can use
// Kadane's algorithm to find the maximum subarray sum. Taking the max out of all these max subarray sums, we get the max sum rectangle

#include <bits/stdc++.h>
using namespace std;

int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
    int ans = -1000000007;
    vector<vector<int>> pre;
    for(int i=0; i<R; i++) {
        vector<int> temp;
        int sum = 0;
        for(int j=0; j<C; j++) {
            sum += M[i][j];
            temp.push_back(sum);
        }
        pre.push_back(temp);
    }
    for(int i=0; i<C; i++) {
        for(int j=i; j<C; j++) {
            int temp[R] = {};
            for(int row=0; row<R; row++) {
                int sum;
                if(i==0) sum = pre[row][j];
                else sum = pre[row][j] - pre[row][i-1];
                temp[row] = sum;
            }
            int k = 0, mx = temp[0];
            for(int i=0; i<R; i++) {
                k += temp[i];
                if(k < 0) k = 0;
                else mx = max(mx, k);
            }
            ans = max(ans, mx);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> M = {
        {1,2,-1,-4,-20},
        {-8,-3,4,2,1},
        {3,8,10,1,3},
        {-4,-1,1,7,-6}
    };

    int r = M.size();
    int c = M[0].size();

    cout << maximumSumRectangle(r, c, M);
}
