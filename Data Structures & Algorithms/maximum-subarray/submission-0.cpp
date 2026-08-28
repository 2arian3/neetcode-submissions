class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int temp = 0;

        for (const auto& num: nums) {
            temp += num;
            maxSum = max(maxSum, temp);
            if (temp < 0) {
                temp = 0;
            }
        }

        return maxSum;
    }
};
