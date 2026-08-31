class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        unordered_map<char, int> lastSeen;

        for (int i = 0; i < n; i++)
            lastSeen[s[i]] = i;

        vector<int> res;

        int from = 0;
        int to = 0;
        while (to < n) {
            int i = from;
            while (i <= to) {
                to = max(to, lastSeen[s[i++]]);
            }
            res.push_back(to - from + 1);
            from = ++to;
        }

        return res;
    }
};
