class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<pair<int, string>> st;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                string char_count = {s[i]};
                while (isdigit(s[++i])) {
                    char_count += s[i];
                }
                st.push({stoi(char_count), ""});
            } else if (s[i] == ']') {
                auto [count, str] = st.top();
                st.pop();
                string strToAdd = "";
                while (count-- > 0)
                    strToAdd += str;
                if (!st.empty()) {
                    auto [count, str] = st.top();
                    st.pop();
                    st.push({count, str + strToAdd});
                } else {
                    res += strToAdd;
                }
            } else {
                if (st.empty())
                    res += s[i];
                else {
                    auto [count, str] = st.top();
                    st.pop();
                    st.push({count, str + s[i]});
                }
            }
        }

        return res;
    }
};