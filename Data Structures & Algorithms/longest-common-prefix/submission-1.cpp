class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        int currI = 0;
        string longest;

        while (i < strs.size()) {
            if (strs[i].size() || i + 1 == strs.size())
                break;
            i++;
        }

        while (currI < strs[i].size()) {
            char currC = strs[i][currI];

            for (const auto& str: strs)
                if (str[currI] != currC)
                    return longest;
            
            longest += currC;
            currI++;
        }

        return longest;
    }
};