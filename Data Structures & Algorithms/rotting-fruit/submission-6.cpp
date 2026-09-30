class Solution {
private:
    int ROWS;
    int COLS;

    int dirs[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};

public:
    int orangesRotting(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1)
                    fresh++;
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }

        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [d0, d1]: dirs) {
                    int nr = d0 + r;
                    int nc = d1 + c;

                    if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS || grid[nr][nc] != 1)
                        continue;
                    
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};
