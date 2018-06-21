class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ans = 0;
        int min_ = prices[0];
        int size = prices.size();
        for(int i = 1; i < size; i++) {
            if(prices[i] > min_) {
                ans = max(ans, prices[i] - min_);
            }
            else {
                min_ = prices[i];
            }
        }
        return ans;
    }
};