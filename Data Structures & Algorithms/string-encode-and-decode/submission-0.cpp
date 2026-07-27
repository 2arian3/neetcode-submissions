class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (const auto& str: strs)
            res += to_string(str.length()) + "#" + str;

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (j < s.length() && s[j] != '#') {
                j++;
            }
            
            int len = stoi(s.substr(i, j - i));
            
            i = j + 1;
            
            res.push_back(s.substr(i, len));
            
            i += len;
        }

        return res;
    }
};
