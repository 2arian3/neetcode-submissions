class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        unordered_set<int> taken;
        backtrack(nums, curr, taken);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& curr, unordered_set<int>& taken) {
        if (curr.size() == nums.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (taken.contains(nums[i]))
                continue;
            curr.push_back(nums[i]);
            taken.insert(nums[i]);
            backtrack(nums, curr, taken);
            curr.pop_back();
            taken.erase(nums[i]);
        }

        return;
    }
};
