class Solution {
private:
    int getAscii(char c) {
        if (c >= 'a')
            return c - 'a';
        return c - 'A' + 26;
    }

public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        vector<int> sFreq(52, 0);
        vector<int> tFreq(52, 0);

        int l = 0;
        int r = 0;

        int required = 0;
        int matching = 0;

        for (const auto& c: t)
            if (tFreq[getAscii(c)]++ == 0)
                required++;

        int minLength = INT_MAX;
        int startIdx = l;

        while (r < s.size()) {
            int newCharAscii = getAscii(s[r]);
            sFreq[newCharAscii]++;
            
            if (sFreq[newCharAscii] == tFreq[newCharAscii])
                matching++;
            
            while (l <= r && matching == required) {
                if (r - l + 1 < minLength) {
                    startIdx = l;
                    minLength = r - l + 1;
                }

                int removingCharAscii = getAscii(s[l]);
                if (sFreq[removingCharAscii] == tFreq[removingCharAscii])
                    matching--;

                l++;
                sFreq[removingCharAscii]--;
            }
            
            r++;
        }

        return minLength != INT_MAX ? s.substr(startIdx, minLength) : "";
    }
};
