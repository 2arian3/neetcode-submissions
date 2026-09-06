class Solution {
private:
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int, int>> q;
        unordered_set<int> notVisited;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1') {
                    notVisited.insert(j + i * COLS);
                }
            }
        }

        int res = 0;

        while (!notVisited.empty()) {
            int toExplore = *notVisited.begin();
            int r = toExplore / COLS;
            int c = toExplore % COLS;
            notVisited.erase(toExplore);

            q.push({r, c});
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                for (const auto& [dr, dc]: dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS)
                        continue;
                    if (notVisited.contains(nc + nr * COLS)) {
                        notVisited.erase(nc + nr * COLS);
                        q.push({nr, nc});
                    }
                }
            }

            res++;
        }

        return res;
    }
};
