class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(candidates, curr, target, 0, 0);
        return res;
    }

    void backtrack(vector<int>& nums,
                   vector<int>& curr,
                   int target,
                   int sum,
                   int start) {

        if (sum == target) {
            res.push_back(curr);
            return;
        }

        if (sum > target)
            return;

        for (int i = start; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(nums, curr, target, sum + nums[i], i);
            curr.pop_back();
        }
    }
};