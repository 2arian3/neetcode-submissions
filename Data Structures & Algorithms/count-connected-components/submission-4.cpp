class Solution {
private:
    int components = 0;

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjs;

        for (const auto& e: edges) {
            adjs[e[0]].push_back(e[1]);
            adjs[e[1]].push_back(e[0]);
        }

        unordered_set<int> visited;

        for (int i = 0; i < n; i++) {
            if (!visited.contains(i)) {
                dfs(adjs, visited, i);
                components++;
            }
        }

        return components;
    }

    void dfs(unordered_map<int, vector<int>>& adjs, unordered_set<int>& visited, int toVisit) {
        if (visited.contains(toVisit))
            return;

        visited.insert(toVisit);

        for (const auto& nei: adjs[toVisit])
            dfs(adjs, visited, nei);

        return;
    }
};
