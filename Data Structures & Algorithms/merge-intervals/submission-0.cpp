class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        for (const auto& in: intervals) {
            if (!res.empty() && res.back()[1] >= in[0]) {
                res.back()[1] = max(res.back()[1], in[1]);
            } else
                res.push_back(in);
        }

        return res;
    }
};
