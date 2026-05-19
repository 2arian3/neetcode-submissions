class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int max_length = 0;
        
        unordered_map<char, int> last_seen_char_pos = {};

        for (int right = 0; right < s.length(); right++) {
            char curr = s[right];

            if (last_seen_char_pos.count(curr) && last_seen_char_pos[curr] >= left) {
                left = last_seen_char_pos[curr] + 1;
            }

            last_seen_char_pos[curr] = right;

            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};
