class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        unordered_map<int, vector<int>> adjs;
        unordered_map<int, bool> isLand;
        unordered_set<int> visited;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                isLand[i * cols + j] = (grid[i][j] == '1');
            }
        }

        for (const auto& [pos, land] : isLand) {
            if (!land)
                continue;

            int col = pos % cols;

            if (isLand.contains(pos - cols) && isLand[pos - cols])
                adjs[pos].push_back(pos - cols);

            if (isLand.contains(pos + cols) && isLand[pos + cols])
                adjs[pos].push_back(pos + cols);

            if (col > 0 &&
                isLand.contains(pos - 1) &&
                isLand[pos - 1])
                adjs[pos].push_back(pos - 1);

            if (col < cols - 1 &&
                isLand.contains(pos + 1) &&
                isLand[pos + 1])
                adjs[pos].push_back(pos + 1);
        }

        int islands = 0;

        for (const auto& [pos, land] : isLand) {
            if (!land || visited.contains(pos))
                continue;

            dfs(pos, adjs, visited);
            islands++;
        }

        return islands;
    }

    void dfs(int node,
             unordered_map<int, vector<int>>& adjs,
             unordered_set<int>& visited) {

        if (visited.contains(node))
            return;

        visited.insert(node);

        for (int nei : adjs[node])
            dfs(nei, adjs, visited);
    }
};