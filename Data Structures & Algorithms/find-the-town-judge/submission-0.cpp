class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inOut(n + 1, 0);

        for (const auto& t: trust) {
            inOut[t[1]]++;
            inOut[t[0]]--;
        }

        for (int i = 1; i <= n; i++) {
            if (inOut[i] == n - 1)
                return i;
        }

        return -1;
    }
};