class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> s;

        for (const auto& num: nums)
            s.insert(num);
        
        for (const auto& num: nums) {
            int temp = num;
            while (s.contains(temp++));
            longest = max(longest, temp - num - 1);
        }

        return longest;
    }
};
