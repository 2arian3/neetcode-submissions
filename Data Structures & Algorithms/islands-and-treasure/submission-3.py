class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        ROWS, COLS = len(grid), len(grid[0])

        queue = deque()
        dirs = {
            (0, 1), (1, 0), (0, -1), (-1, 0)
        }

        INF = 2147483647

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 0:
                    queue.append((i, j))

        while len(queue):
            row, col = queue.popleft()

            for (rowDir, colDir) in dirs:
                nRow = rowDir + row
                nCol = colDir + col

                if 0 <= nRow < ROWS and 0 <= nCol < COLS and grid[nRow][nCol] == INF:
                    grid[nRow][nCol] = grid[row][col] + 1
                    queue.append((nRow, nCol))
                    

