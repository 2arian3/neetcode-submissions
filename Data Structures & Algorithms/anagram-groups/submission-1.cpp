class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> result = {};

        for (string str : strs) {
            vector<int> counter(26);
            string key = "";

            for (char c : str) {
                counter[c - 'a']++;
            }

            for (int i = 0; i < 26; i++) {
                key += to_string(counter[i]) + "#";
            }

            anagrams[key].push_back(str);
        }

        for (auto &entry : anagrams) {
            result.push_back(entry.second);
        }

        return result;
    }
};
