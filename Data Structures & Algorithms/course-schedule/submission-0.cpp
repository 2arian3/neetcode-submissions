class Solution {
private:
    unordered_set<int> visited;
    unordered_map<int, vector<int>> dependencies;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++)
            dependencies[i] = {};

        for (const auto& pre: prerequisites)
            dependencies[pre[0]].push_back(pre[1]);
        
        for (int i = 0; i < numCourses; i++)
            if (!dfs(i))
                return false;

        return true;
    }

    bool dfs(int course) {
        if (visited.contains(course))
            return false;
        
        if (dependencies[course].empty())
            return true;
        
        visited.insert(course);

        for (const auto& d: dependencies[course]) {
            if (!dfs(d))
                return false;
        }

        visited.erase(course);
        dependencies[course].clear();
        return true;
    }
};
