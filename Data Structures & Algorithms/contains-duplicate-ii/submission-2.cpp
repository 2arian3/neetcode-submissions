class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++) {
            if (m.contains(nums[i]) && abs(i - m[nums[i]]) <= k && m[nums[i]] != i)
                return true;
        }

        return false;
    }
};