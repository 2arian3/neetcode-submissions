class Solution {
private:
    vector<vector<int>> res;
    unordered_map<int, int> cnt;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for(const auto& num: nums)
            cnt[num]++;
        
        vector<int> perm;
        backtrack(nums, perm);

        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& perm) {
        if (nums.size() == perm.size()) {
            res.push_back(perm);
            return;
        }

        for (auto& [num, c]: cnt) {
            if (c <= 0)
                continue;

            c--;
            perm.push_back(num);
            backtrack(nums, perm);
            perm.pop_back();
            c++; 
        }        
    }
};