class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = INT_MAX;

        for (const auto& p: prices) {
            profit = max(profit, p - buy);
            buy = min(buy, p);
        }

        return profit;
    }
};
