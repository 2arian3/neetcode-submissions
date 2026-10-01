class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (s[i] == s[j] && (i - j < 2 || dp[j+1][i-1])) {
                    dp[j][i] = true;
                    res++;
                }
            }
        }

        return res;
    }
};
