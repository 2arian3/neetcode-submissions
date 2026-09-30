class Solution {
private:
    vector<vector<int>> res;
    int target;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        this->target = target;

        int currSum = 0;
        vector<int> curr = {};

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, curr, currSum, 0);

        return res;
    }

    void backtrack(vector<int>& candidates, vector<int>& curr, int& currSum, int i) {
        if (currSum == target) {
            res.push_back(curr);
            return;
        }

        if (i >= candidates.size() || currSum > target)
            return;

        curr.push_back(candidates[i]);
        currSum += candidates[i];

        backtrack(candidates, curr, currSum, i + 1);

        curr.pop_back();
        currSum -= candidates[i];

        while (i < candidates.size() - 1 && candidates[i] == candidates[i + 1])
            i++;

        backtrack(candidates, curr, currSum, i + 1);
    }
};
