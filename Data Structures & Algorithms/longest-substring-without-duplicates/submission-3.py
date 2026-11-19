class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r, maxLen = 0, 0, 0
        charLastSeen = defaultdict(lambda: -1)

        while r < len(s):
            if charLastSeen[s[r]] != -1:
                l = max(l, charLastSeen[s[r]] + 1)
            
            charLastSeen[s[r]] = r

            maxLen = max(maxLen, r - l + 1)
            
            r += 1

        return maxLen