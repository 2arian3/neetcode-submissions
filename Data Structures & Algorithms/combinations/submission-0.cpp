class Solution {
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        backtrack(n, k, 1, curr);
        return res;
    }

    void backtrack(int& n, int& k, int from, vector<int>& curr) {
        if (curr.size() > k)
            return;

        if (curr.size() == k) {
            res.push_back(curr);
            return;
        }

        for (int i = from; i <= n; i++) {
            curr.push_back(i);
            backtrack(n, k, i + 1, curr);
            curr.pop_back();
        }
    }
};