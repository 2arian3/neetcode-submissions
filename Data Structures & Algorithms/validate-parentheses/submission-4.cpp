class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        set<char> openings = {'{', '[', '('};
        map<char, char> m = {
            {'{', '}'},
            {'(', ')'},
            {'[', ']'}
        };

        for (auto c: s) {
            if (openings.contains(c))
                st.push(c);
            else {
                if (st.empty() || c != m[st.top()])
                    return false;
                st.pop();
            }
        }

        return st.empty() ? true : false;
    }
};
