class Solution {
private:
    vector<int> res;
    unordered_set<int> visiting;
    unordered_set<int> visited;
    unordered_map<int, vector<int>> preMap;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        for (const auto& pre : prerequisites) {
            preMap[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i))
                return {};
        }

        return res;
    }

private:
    bool dfs(int course) {
        if (visiting.count(course))
            return false;

        if (visited.count(course))
            return true;

        visiting.insert(course);

        for (int pre : preMap[course]) {
            if (!dfs(pre))
                return false;
        }

        visiting.erase(course);
        visited.insert(course);
        res.push_back(course);

        return true;
    }
};