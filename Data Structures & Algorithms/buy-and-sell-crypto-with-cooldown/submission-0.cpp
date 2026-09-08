class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp1_buy = 0;
        int dp2_buy = 0;
        int dp1_sell = 0;

        for (int i = prices.size() - 1; i >= 0; i--) {
            int buy = max(dp1_buy, dp1_sell - prices[i]);
            int sell = max(dp1_sell, dp2_buy + prices[i]);

            dp2_buy = dp1_buy;
            dp1_buy = buy;
            dp1_sell = sell;
        }

        return dp1_buy;
    }
};
