// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int cash = 0, hold = -1 * prices[0];
    for(int i=1; i<n; i++) {
        cash = max(cash, hold + prices[i] - fee);
        hold = max(hold, cash - prices[i]);
    }
    return cash;
}

int main() {
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;
    cout << maxProfit(prices, fee);
}
