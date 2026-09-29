class Solution {
private:
    vector<int> res;
    unordered_set<int> taken;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> adjs;

        for (int i = 0; i < numCourses; i++)
            adjs[i] = {};

        for (const auto& courses: prerequisites)
            adjs[courses[0]].push_back(courses[1]);

        for (int i = 0; i < numCourses; i++) {
            unordered_set<int> visited;
            if (!taken.contains(i) && !dfs(adjs, visited, i))
                return {};
        }
        
        return res;
    }

    bool dfs(unordered_map<int, vector<int>>& adjs, unordered_set<int>& visited, int toTake) {
        if (taken.contains(toTake))
            return true;

        if (visited.contains(toTake))
            return false;

        visited.insert(toTake);

        for (const auto& pre: adjs[toTake]) {
            // cout << toTake << " " << pre << endl;
            if (!dfs(adjs, visited, pre))
                return false;
        }

        taken.insert(toTake);
        res.push_back(toTake);
        return true;
    }
};
