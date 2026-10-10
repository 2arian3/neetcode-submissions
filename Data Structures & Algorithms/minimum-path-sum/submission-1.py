class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        ROWS, COLS = len(grid), len(grid[0])

        for col in range(1, COLS):
            grid[0][col] += grid[0][col - 1]
        
        for row in range(1, ROWS):
            grid[row][0] += grid[row - 1][0]

        for row in range(1, ROWS):
            for col in range(1, COLS):
                grid[row][col] += min(grid[row - 1][col], grid[row][col - 1])

        return grid[ROWS - 1][COLS - 1]