class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int dirs[4][2] = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}
        };

        queue<pair<int, int>> q;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc]: dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != INT_MAX)
                        continue;

                    grid[nr][nc] = grid[r][c] + 1;

                    q.push({nr, nc});
                }
            }
        }

        return;
    }
};
