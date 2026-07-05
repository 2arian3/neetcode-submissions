class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<int> subset;
        backtrack(subset, 0);
        return res;
    }

    void backtrack(vector<int> subset, int i) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(subset, i + 1);
        subset.pop_back();
        backtrack(subset, i + 1);

        return;
    }
};
