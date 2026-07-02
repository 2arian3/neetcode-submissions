class Solution {
private:
    vector<vector<string>> res;

    bool isPalindrome(string s, int i, int j) {
        int l = i;
        int r = j;

        while (l < r && s[l] == s[r]) {
            l++;
            r--;
        }

        return l >= r;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        backtrack(0, s, partitions);
        return res;
    }

    void backtrack(int i, string s, vector<string> partitions) {
        if (i >= s.length()) {
            res.push_back(partitions);
            return;
        }

        for (int j = i; j < s.length(); j++) {
            if (isPalindrome(s, i, j)) {
                partitions.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1, s, partitions);
                partitions.pop_back();
            }
        }

        return;
    }

};
