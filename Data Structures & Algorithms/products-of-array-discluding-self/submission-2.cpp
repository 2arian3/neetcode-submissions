class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;

        vector<int> leftProducts(nums.size(), 1);
        vector<int> rightProducts(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
            leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
        
        for (int i = nums.size() - 2; i >= 0; i--)
            rightProducts[i] = rightProducts[i + 1] * nums[i + 1];

        for (int i = 0; i < nums.size(); i++)
            res.push_back(leftProducts[i] * rightProducts[i]);
        
        return res;
    }
};
