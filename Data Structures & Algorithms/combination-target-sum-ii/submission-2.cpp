class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, curr, 0, 0, target);
        return res;
    }

    void backtrack(vector<int>& candidates, vector<int>& curr, int i, int sum, int target) {
        if (sum == target) {
            res.push_back(curr);
            return;
        } else if (sum > target || i == candidates.size()) {
            return;
        }

        curr.push_back(candidates[i]); 
        backtrack(candidates, curr, i + 1, sum + candidates[i], target);
        curr.pop_back();

        while (i + 1 < candidates.size() && candidates[i + 1] == candidates[i])
            i++;
        backtrack(candidates, curr, i + 1, sum, target);

        return;
    }
};
