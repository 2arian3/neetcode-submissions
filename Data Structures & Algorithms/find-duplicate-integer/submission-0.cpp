class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for (auto num: nums) {
            int i = abs(num) - 1;
            if (nums[i] < 0) {
                return abs(num);
            }
            nums[i] *= -1;
        }
        return -1;
    }
};
