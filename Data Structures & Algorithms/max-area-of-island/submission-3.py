class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])

        dirs = {
            (0, 1), (1, 0), (-1, 0), (0, -1)
        }

        maxArea = 0;

        def dfs(row: int, col: int) -> int:
            if row >= ROWS or row < 0 or col >= COLS or col < 0 or grid[row][col] == 0:
                return 0

            grid[row][col] = 0

            area = 0
            for (rowDir, colDir) in dirs:
                area += dfs(row + rowDir, col + colDir)
            
            return 1 + area

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    maxArea = max(maxArea, dfs(i, j))

        return maxArea