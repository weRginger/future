class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee);
            /*
             * We can transform cash first without using temporary variables
             * because selling and buying on the same day can't be better than
             * just continuing to hold the stock.
             */
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};