#include <bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(n == 0 || n == 1) return 0;
    int profit[k + 1][n + 1];
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;

    for (int i = 1; i <= k; i++) {
        int prevDiff = INT_MIN;
        for (int j = 1; j < n; j++) {
            prevDiff = max(prevDiff,
                           profit[i - 1][j - 1] - prices[j - 1]);
            profit[i][j] = max(profit[i][j - 1],
                               prices[j] + prevDiff);
        }
    }

    return profit[k][n - 1];
}

int main() {
    int k = 5;
    vector<int> prices = {132,65,8,384,8,54,87,84,8,2,1,5,8,87,45,6,47,45,84,4};
    cout << maxProfit(k, prices);
}
