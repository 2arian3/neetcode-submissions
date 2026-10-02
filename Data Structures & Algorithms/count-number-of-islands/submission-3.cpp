class Solution {
private:
    vector<vector<int>> dirs = {
        {0, 1}, {1, 0}, {-1, 0}, {0, -1}
    };

    int ROWS, COLS;

public:
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        int islands = 0;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }

        return islands;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row >= ROWS || row < 0 || col >= COLS || col < 0 || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';

        for (const auto& dir: dirs) {
            dfs(grid, row + dir[0], col + dir[1]);
        }

        return;
    }
};
