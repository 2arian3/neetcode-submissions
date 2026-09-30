class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        bool exploded = false;

        for (const auto& astro: asteroids) {
            exploded = false;
            while (!st.empty() && !exploded && st.back() * astro < 0 && astro < 0) {
                if (abs(st.back()) >= abs(astro)) {
                    exploded = true;
                    if (abs(st.back()) == abs(astro))
                        st.pop_back();
                }
                else
                    st.pop_back();
            }
            if (!exploded)
                st.push_back(astro);
        }

        return st;
    }
};