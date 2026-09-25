class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        vector<string> st;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            }
            else if (token == "..") {
                if (!st.empty()) {
                    st.pop_back();
                }
            } 
            else {
                st.push_back(token);
            }
        }

        string res = "";
        for (const auto& dir : st) {
            res += "/" + dir;
        }

        return res.empty() ? "/" : res;
    }
};