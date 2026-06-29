class Solution {
private:
    unordered_map<char, vector<char>> dmap = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
    vector<string> res;
    string d;
public:
    vector<string> letterCombinations(string digits) {
        d = digits;
        backtrack("", 0);
        return res;
    }
    void backtrack(string currString, int currI) {
        if (currString.length() == d.length() && currString.length() != 0) {
            res.push_back(currString);
            return;
        }

        for (int i = currI; i < d.length(); i++) {
            for (auto c: dmap[d[i]]) {
                currString += c;
                backtrack(currString, i+1);
                currString.pop_back();
            }
        }

        return;
    }
};
