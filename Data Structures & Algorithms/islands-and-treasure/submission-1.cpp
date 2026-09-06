class Solution {
private:
    int dirs[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0)
                    q.push({i, j});

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [rd, cd]: dirs) {
                int nr = r + rd;
                int nc = c + cd;

                if (nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;
                
                if (grid[nr][nc] == INT_MAX) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
