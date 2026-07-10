class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;

        for (const auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int res = 0;
        unordered_set<int> visited;

        for (int i = 0; i < n; i++) {
            if (visited.contains(i))
                continue;
            dfs(visited, g, i, -1);
            res++;
            if (visited.size() == n)
                break;
        }

        return res;
    }

    void dfs(unordered_set<int>& visited, unordered_map<int, vector<int>>& g, int node, int parent) {
        if (visited.contains(node))
            return;
        
        visited.insert(node);

        for (const auto n: g[node]) {
            if (n == parent)
                continue;
            dfs(visited, g, n, node);
        }
    }
};
