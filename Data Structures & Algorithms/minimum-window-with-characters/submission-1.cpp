class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        
        int wmap[128] = {0}, tmap[128] = {};
        int required = 0;
        int have = 0;

        for (int i = 0; i < t.size(); i++)
            if (tmap[t[i]]++ == 0)
                required++;

        int start = 0;
        int len = INT_MAX;

        for (int r = 0, l = 0; r < s.size(); r++) {
            wmap[s[r]]++;

            if (wmap[s[r]] == tmap[s[r]])
                have++;

            while (have == required) {
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    start = l;
                }
                if (wmap[s[l]] == tmap[s[l]]) {
                    have--;
                }
                wmap[s[l]]--;
                l++;
            }
        }

        cout << start << ' ' << len << endl;

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
