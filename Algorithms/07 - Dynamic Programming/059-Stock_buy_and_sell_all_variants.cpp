// STOCK BUY AND SELL PROBLEMS
// Given the price of stocks on 'n' days, find the maximum amount of profit you can make under various conditions

// =================================================================================================================
// VARIANT 1 : WE CAN COMPLETE AT MOST 1 TRANSACTION IN TOTAL
// Explanation : We simply need to maximize the difference between the price of stock on a day and the minimum price
// of stock in all the days preceding that day

int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    int hold = prices[0], cash = 0;
    for(int i=0; i<prices.size(); i++) {
        hold = min(hold, prices[i]);
        cash = max(cash, prices[i] - hold);
    }
    return cash;
}

// ==================================================================================================================
// VARIANT 2 : WE CAN MAKE AS MANY TRANSACTIONS AS WE WISH
// Explanation : Given problem needs dynamic programming. We start from the first day and keep in track wheter we own
// a stock or not. In case we own a stock, we can either choose to keep it or sell it on any particular day. In case
// we do not own a stock, we can choose to either buy stock or do nothing on any particular day. We have to maxumize
// these values using dynamic programming

int dp[100005][2];

int func(int i, bool own, const vector<int>&v) {
    if(i == v.size()) return 0;
    if(own) {
        if(dp[i][1] != -1) return dp[i][1];
        int opt1 = func(i+1, true, v);
        int opt2 = v[i] + func(i+1, false, v);
        dp[i][1] = max(opt1, opt2);
        return dp[i][1];
    }
    else {
        if(dp[i][0] != -1) return dp[i][0];
        int opt1 = func(i+1, false, v);
        int opt2 = func(i+1, true, v) - v[i];
        dp[i][0] = max(opt1, opt2);
        return dp[i][0];
    }
}

int maxProfit(const vector<int> &A) {
    memset(dp, -1, sizeof dp);
    if(A.size() == 0) return 0;
    return func(0, false, A);
}
