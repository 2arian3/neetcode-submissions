class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagrams;

        for (const auto& str: strs) {
            string hash = "";
            vector<int> counter(26, 0);
            for (const auto& c: str) {
                counter[c - 'a']++;
            }
            for (int i = 0; i < 26; i++)
                hash += to_string(counter[i]) + ',';

            anagrams[hash].push_back(str);
        }

        for (const auto& [_, strings]: anagrams) {
            res.push_back(strings);
        }

        return res;
    }
};
