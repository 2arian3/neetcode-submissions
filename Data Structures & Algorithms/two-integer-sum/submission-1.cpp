class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
            m[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            if (m.find(temp) != m.end() && i != m[temp]) {
                res.push_back(i);
                res.push_back(m[temp]);
                break;
            }
        }

        return res;
    }
};
