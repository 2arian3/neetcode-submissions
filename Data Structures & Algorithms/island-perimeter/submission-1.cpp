class Solution {
private:
    int ROWS, COLS;
    vector<vector<int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        ROWS = grid.size();
        COLS = grid[0].size();

        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j])
                    return dfs(grid, i, j);
        
        return 0;
    }

    int dfs(vector<vector<int>>& grid, int row, int col) {
        if (row >= ROWS || col >= COLS || row < 0 || col < 0 || grid[row][col] == 0)
            return 1;

        if (grid[row][col] == -1)
            return 0;

        grid[row][col] = -1;
        
        int perimeter = dfs(grid, row + 1, col) + dfs(grid, row, col + 1) + dfs(grid, row - 1, col) + dfs(grid, row, col - 1);

        return perimeter;
    }
};