class Solution {
private:
    vector<string> res;
    int N;
public:
    vector<string> generateParenthesis(int n) {
        N = n;
        string curr = "";
        backtrack(0, 0, curr);
        return res;
    }

    void backtrack(int open, int close, string& curr) {
        if (open < close || open > N)
            return;

        if (open == N && open == close) {
            res.push_back(curr);
            return;
        }

        curr += "(";
        backtrack(open + 1, close, curr);
        curr.pop_back();

        curr += ")";
        backtrack(open, close + 1, curr);
        curr.pop_back();
    }
};
