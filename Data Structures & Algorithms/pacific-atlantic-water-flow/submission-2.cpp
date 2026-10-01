class Solution {
private:
    vector<vector<int>> dirs = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}
    };

    int ROWS;
    int COLS;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> visitedP(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> visitedA(ROWS, vector<bool>(COLS, false));
        
        for (int i = 0; i < COLS; i++) {
            dfs(heights, visitedP, 0, i);
            dfs(heights, visitedA, ROWS - 1, i);
        }

        for (int i = 0; i < ROWS; i++) {
            dfs(heights, visitedP, i, 0);
            dfs(heights, visitedA, i, COLS - 1);
        }

        vector<vector<int>> res;

        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (visitedP[i][j] && visitedA[i][j])
                    res.push_back({i, j});
        
        return res;
    }

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int row, int col) {
        if (visited[row][col])
            return;

        visited[row][col] = true;

        for (const auto& dir: dirs) {
            int nr = dir[0] + row;
            int nc = dir[1] + col;
            
            if (nr < 0 || nr >= ROWS || nc < 0 || nc >= COLS)
                continue;

            if (heights[nr][nc] < heights[row][col])
                continue;

            dfs(heights, visited, nr, nc);
        }
    }
};
