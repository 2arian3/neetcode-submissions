class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> neighbours(edges.size() + 1);

        for (const auto& e : edges) {
            int ai = e[0];
            int bi = e[1];

            vector<bool> visited(edges.size() + 1, false);

            if (dfs(visited, neighbours, ai, bi))
                return {ai, bi};

            neighbours[ai].push_back(bi);
            neighbours[bi].push_back(ai);
        }

        return {};
    }

    bool dfs(vector<bool>& visited, vector<vector<int>>& neighbours, int node, int target) {
        if (node == target)
            return true;

        visited[node] = true;

        for (int next : neighbours[node]) {
            if (!visited[next] && dfs(visited, neighbours, next, target))
                return true;
        }

        return false;
    }
};
