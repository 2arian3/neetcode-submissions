class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> picked(nums.size(), false);
        vector<int> curr;
        backtrack(nums, curr, picked);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& soFar, vector<bool>& picked) {
        if (nums.size() == soFar.size()) {
            res.push_back(soFar);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!picked[i]) {
                picked[i] = true;
                soFar.push_back(nums[i]);
                backtrack(nums, soFar, picked);
                picked[i] = false;
                soFar.pop_back();
            }
        }
    }
};
