class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])
        dirs = {
            (-1, 0), (0, -1), (1, 0), (0, 1)
        }

        islands = 0

        def dfs(row: int, col: int):
            if row >= ROWS or row < 0 or col >= COLS or col < 0 or grid[row][col] == "0":
                return
            
            grid[row][col] = "0"

            for d in dirs:
                dfs(row + d[0], col + d[1])

        
        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == "1":
                    dfs(i, j)
                    islands += 1


        return islands