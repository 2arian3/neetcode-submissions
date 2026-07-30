class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int largest = 0;
        stack<pair<int, int>> s;

        for (int i = 0; i < heights.size(); i++) {
            int from = i;

            while (!s.empty() && s.top().second > heights[i]) {
                auto [index, h] = s.top();
                s.pop();
                largest = max(largest, h * (i - index));
                from = index;
            }

            s.push({from, heights[i]});
        }

        while (!s.empty()) {
            auto [index, h] = s.top();
            largest = max(largest, h * ((int)heights.size() - index));
            s.pop();
        }

        return largest;
    }
};
