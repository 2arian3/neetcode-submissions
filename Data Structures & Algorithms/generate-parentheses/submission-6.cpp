class Solution {
private:
    int N;
    vector<string> res;

public:
    vector<string> generateParenthesis(int n) {
        N = n;
        string curr = "";

        backtrack(curr, 0, 0);
        
        return res;
    }

    void backtrack(string& curr, int opened, int closed) {
        if (opened > N || closed > opened)
            return;

        if (opened == closed && opened == N) {
            res.push_back(curr);
            return;
        }

        curr += "(";
        backtrack(curr, opened + 1, closed);
        curr.pop_back();

        curr += ")";
        backtrack(curr, opened, closed + 1);
        curr.pop_back();

        return;
    }
};
