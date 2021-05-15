// PS : https://leetcode.com/problems/house-robber/
// Explanation : This is a simple example problem for Decision Making type questions in Dynamic programming. Here, there are just 2 choices for each house - either rob it or not rob it.
// In case the robber decides to rob that house, then the total sum up till now would be dp[n-1][0] + nums[i], because in that case the last house must definitely not be robbed. In case the
// the robeer decides not to rob the house, then the total sum would be max(dp[i-1][0], dp[i-1][1]) because it is not necessary that robbing alternate houses would give optimal result, and
// leaving out consecutive houses can also give optimal result in some cases. For eg. the case taken in the given solution. Here, ignoring the consecutive houses at indices 2 & 3 gives us
// an optimal result

#include <bits/stdc++.h>
using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    int dp[n][2];
    dp[0][0] = 0;
    dp[0][1] = nums[0];

    for(int i=1; i<n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = nums[i] + dp[i-1][0];
    }

    return max(dp[n-1][0], dp[n-1][1]);
}

int main() {
    vector<int> v = {4,1,9,1,1,8,1,12};
    cout << rob(v);
}
