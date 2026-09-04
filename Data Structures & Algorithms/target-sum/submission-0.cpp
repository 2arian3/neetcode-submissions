class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n + 1);

        dp[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (const auto& sums: dp[i]) {
                dp[i + 1][sums.first + nums[i]] += sums.second;
                dp[i + 1][sums.first - nums[i]] += sums.second;
            }
        }

        return dp[n][target];
    }
};
