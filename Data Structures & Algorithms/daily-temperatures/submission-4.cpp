class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> s;

        for (int i = 0 ; i < temperatures.size(); i++) {
            int temp = temperatures[i];
            while (!s.empty() && s.top().first < temp) {
                auto curr = s.top();
                res[curr.second] = i - curr.second;
                s.pop();
            }
            s.push({temp, i});
        }

        return res;
    }
};
