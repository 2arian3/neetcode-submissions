class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        vector<vector<int>> res;
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int target = -nums[i] - nums[j];

                if (target < nums[j])
                    continue;

                count[nums[j]]--;
                if (count[target] > 0) {
                    res.push_back({nums[i], nums[j], target});
                }
                count[nums[j]]++;
            }
            count[nums[i]]++;
        }

        return res;
    }
};