class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = nums[0];

        int dp0 = 1;
        int dp1 = 1;
        for (const auto& num: nums) {
            int temp = num * dp0;
            dp0 = max(num, max(num * dp0, num * dp1));
            dp1 = min(num, min(temp, num * dp1));
            m = max(m, dp0);
        }

        return m;
    }
};
