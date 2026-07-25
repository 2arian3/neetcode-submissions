class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        bool inserted = false;
        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][0] >= newInterval[0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }
        
        if (!inserted) {
            intervals.push_back(newInterval);
        }

        int i = 0;
        while (i < intervals.size()) {
            if (res.empty()) {
                res.push_back(intervals[i++]);
                continue;
            }

            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            } else {
                res.push_back(intervals[i]);
            }
            i++;
        }

        return res;
    }
};
