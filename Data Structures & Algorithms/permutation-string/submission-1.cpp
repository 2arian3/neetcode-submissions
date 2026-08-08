class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        int l = 0;
        int r = s1.size() - 1;
        int matches = 0;

        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);

        for (const auto c: s1)
            s1_count[c - 'a']++;

        for (int i = l; i <= r; i++)
            s2_count[s2[i] - 'a']++;

        for (int i = 0; i < 26; i++)
            if (s1_count[i] == s2_count[i])
                matches++;
        
        while (r < s2.size() - 1) {
            if (matches == 26)
                return true;
            l++;
            r++;

            int left_char = s2[l - 1] - 'a';
            if (s2_count[left_char] == s1_count[left_char])
                matches--;
            s2_count[left_char]--;
            if (s2_count[left_char] == s1_count[left_char])
                matches++;

            int right_char = s2[r] - 'a';
            if (s2_count[right_char] == s1_count[right_char])
                matches--;
            s2_count[right_char]++;
            if (s2_count[right_char] == s1_count[right_char])
                matches++;
        }

        return matches == 26;
    }
};
