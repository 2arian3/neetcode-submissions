class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stars;
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == '*') {
                stars.push(i);
            } else {
                if (!st.empty())
                    st.pop();
                else if (!stars.empty())
                    stars.pop();
                else
                    return false;
            }
        }

        while (!st.empty()) {
            if (stars.empty() || stars.top() < st.top())
                break;
            stars.pop();
            st.pop();
        }

        return st.empty();
    }
};
