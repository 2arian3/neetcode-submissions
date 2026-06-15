class Solution {
public:
    vector<string> res;

    vector<string> generateParenthesis(int n) {
        string curr;
        backtrack(curr, 0, 0, n);
        return res;
    }

    void backtrack(string& curr, int open, int close, int n) {
        if (close == open && n == close) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr += '(';
            backtrack(curr, open + 1, close, n);
            curr.pop_back();
        }

        if (close < open) {
            curr += ')';
            backtrack(curr, open, close + 1, n);
            curr.pop_back();
        }

        return;
    }
};
