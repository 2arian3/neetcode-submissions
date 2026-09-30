class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res;
        int i = 0;
        int j = 0;

        while (int(res.size()) != int(word1.size()) + int(word2.size())) {
            if (i < word1.size())
                res += word1[i++];
            
            if (j < word2.size())
                res+= word2[j++];
        }

        return res;
    }
};