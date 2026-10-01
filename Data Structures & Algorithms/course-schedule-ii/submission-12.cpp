class Solution {
private:
    vector<int> res;
    unordered_set<int> taken;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> preM;

        for (int i = 0; i < numCourses; i++)
            preM[i] = {};
        
        for (const auto& pre: prerequisites) {
            preM[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            unordered_set<int> taking;
            if (!taken.contains(i) && !dfs(preM, i, taking))
                return {};
        }

        return res;
    }

    bool dfs(unordered_map<int, vector<int>>& preM, int courseNum, unordered_set<int>& taking) {
        if (taken.contains(courseNum))
            return true;

        if (taking.contains(courseNum))
            return false;

        taking.insert(courseNum);

        for (const auto& pre: preM[courseNum]) {
            if (!dfs(preM, pre, taking))
                return false;
        }

        res.push_back(courseNum);
        taken.insert(courseNum);

        return true;
    }
};
