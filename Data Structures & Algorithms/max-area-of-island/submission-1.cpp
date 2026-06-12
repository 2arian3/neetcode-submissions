class Solution {
public:
    int directs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                maxArea = max(dfs(grid, i, j), maxArea);
            }
        }

        return maxArea;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row < 0 || col < 0 || 
            row >= grid.size() || col >= grid[0].size() ||
            grid[row][col] == 0) {
            return 0;
        }

        grid[row][col] = 0;
        int maxArea = 1;

        maxArea += dfs(grid, row + directs[0][0], col + directs[0][1]);
        maxArea += dfs(grid, row + directs[1][0], col + directs[1][1]);
        maxArea += dfs(grid, row + directs[2][0], col + directs[2][1]);
        maxArea += dfs(grid, row + directs[3][0], col + directs[3][1]);

        return maxArea;
    }
};
