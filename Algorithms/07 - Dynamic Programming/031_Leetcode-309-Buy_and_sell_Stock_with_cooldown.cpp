// PS : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int cash[n];
    int hold[n];
    cash[0] = 0;
    hold[0] = -1 * prices[0];
    for(int i=1; i<n; i++) {
        cash[i] = max(cash[i-1], hold[i-1] + prices[i]);
        if(i==1)
            hold[i] = max(hold[i-1], -1*prices[i]);
        else
            hold[i] = max(hold[i-1], cash[i-2] - prices[i]);
    }
    return max(0, cash[n-1]);
}

int main() {
    vector<int> prices = {1,2,3,0,2};
    cout << maxProfit(prices);
}
