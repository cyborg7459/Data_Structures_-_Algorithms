// STOCK BUY AND SELL PROBLEMS
// Given the price of stocks on 'n' days, find the maximum amount of profit you can make under various conditions

// =================================================================================================================
// VARIANT 1 : WE CAN COMPLETE AT MOST 1 TRANSACTION IN TOTAL
// Explanation : We simply need to maximize the difference between the price of stock on a day and the minimum price
// of stock in all the days preceding that day

int maxProfit1(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    int hold = prices[0], cash = 0;
    for(int i=0; i<prices.size(); i++) {
        hold = min(hold, prices[i]);
        cash = max(cash, prices[i] - hold);
    }
    return cash;
}

// ==================================================================================================================
