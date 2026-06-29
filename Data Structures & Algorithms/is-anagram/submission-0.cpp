class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> sm, tm;
        for (int i = 0; i < s.length(); i++) {
            sm[s[i]]++;
            tm[t[i]]++;
        }

        return sm == tm;
    }
};
