class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)

        for word in strs:
            char_count = {}
            for i in range(26):
                char_count[i] = 0
            
            for char in word:
                char_count[ord(char) - ord('a')] += 1

            anagram_group = ''
            for i in range(26):
                anagram_group += f'#{char_count[i]}'

            anagrams[anagram_group].append(word)

        return list(anagrams.values())