class Solution {
private:
    vector<pair<int, int>> dirs = {
        {-1, 0}, {0, -1}, {1, 0}, {0, 1}
    };
    vector<vector<int>> res;
    int ROWS, COLS;


public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();

        vector<vector<bool>> visitedP(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> visitedA(ROWS, vector<bool>(COLS, false));
        
        for (int i = 0; i < COLS; i++) {
            dfs(heights, 0, i, visitedP);
            dfs(heights, ROWS - 1, i, visitedA);
        }

        for (int i = 0; i < ROWS; i++) {
            dfs(heights, i, 0, visitedP);
            dfs(heights, i, COLS - 1, visitedA);
        }

        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (visitedA[i][j] && visitedP[i][j])
                    res.push_back({i, j});

        return res;
    }

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& water) {
        water[r][c] = true;

        for (auto [rd, cd]: dirs) {
            int nr = rd + r;
            int nc = cd + c;
            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS
                && !water[nr][nc] && heights[nr][nc] >= heights[r][c])
                dfs(heights, nr, nc, water);
        }
    }
};
