class Solution {
public:
    int characterReplacement(string s, int k) {
        int longest = 0;
        int l = 0;
        int maximum_freq = 0;

        unordered_map<char, int> char_count;

        for (int r = 0; r < s.size(); r++) {
            char_count[s[r]]++;
            maximum_freq = max(maximum_freq, char_count[s[r]]);

            if (r - l + 1 - maximum_freq > k) {
                char_count[s[l]]--;
                l++;
            }

            longest = max(longest, r - l + 1);
        }

        return longest;
    }
};
