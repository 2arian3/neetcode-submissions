class Solution {
private:
    vector<vector<int>> res;

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(n, k, 1, curr);
        return res;
    }

    void backtrack(const int& n, const int& k, int i, vector<int>& curr) {
        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }

        if (i > n)
            return;

        curr.push_back(i);
        backtrack(n, k, i + 1, curr);
        curr.pop_back();
        backtrack(n, k, i + 1, curr);
    }
};