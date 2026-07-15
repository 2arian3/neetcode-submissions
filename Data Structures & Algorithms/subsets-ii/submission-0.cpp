class Solution {
private:
    vector<vector<int>> res;
    vector<int> nums;

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->nums = nums;
        sort(this->nums.begin(), this->nums.end());
        vector<int> soFar;
        backtrack(0, soFar);
        return res;
    }

    void backtrack(int index, vector<int>& soFar) {
        if (index == nums.size()) {
            res.push_back(soFar);
            return;
        }

        soFar.push_back(nums[index]);
        backtrack(index + 1, soFar);
        soFar.pop_back();

        while (index + 1 < nums.size() && nums[index] == nums[index + 1])
            index++;
        
        backtrack(index + 1, soFar);
    }
};
