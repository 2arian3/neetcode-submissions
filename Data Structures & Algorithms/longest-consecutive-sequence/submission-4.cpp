class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (const auto& num: nums)
            s.insert(num);
        
        int longest = 0;
        for (const auto& num: nums) {
            if (!s.contains(num - 1)) {
                int len = 1;
                while (s.contains(num + len))
                    len++;
                longest = max(longest, len);
            }
        }

        return longest;
    }
};
