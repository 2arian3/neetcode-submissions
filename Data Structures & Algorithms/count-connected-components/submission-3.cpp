class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (const auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int components = 0;
        unordered_set<int> visited;

        for (int i = 0; i < n; i++) {
            if (visited.contains(i))
                continue;
            dfs(adj, visited, i);
            components++;
        }

        return components;
    }

    void dfs(unordered_map<int, vector<int>>& adj, unordered_set<int>& visited, int node) {
        if (visited.contains(node))
            return;

        visited.insert(node);

        for (const auto& nei: adj[node]) {
            dfs(adj, visited, nei);
        }

        return;
    }
};
