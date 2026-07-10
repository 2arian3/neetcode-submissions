class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n - 1 != edges.size())
            return false;

        unordered_map<int, vector<int>> g;

        for (const auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<bool> visited(n, false);

        if (!dfs(visited, g, 0, -1))
            return false;

        for (const auto& v: visited)
            if (!v)
                return false;

        return true;
    }

    bool dfs(vector<bool>& visited, unordered_map<int, vector<int>>& g, int node, int parent) {
        if (visited[node])
            return false;
        
        visited[node] = true;

        for (const auto n: g[node]) {
            if (n == parent)
                continue;
            if (!dfs(visited, g, n, node))
                return false;
        }

        return true;
    }
};
