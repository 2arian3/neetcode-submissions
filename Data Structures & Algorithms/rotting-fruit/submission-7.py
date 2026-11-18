class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        fresh = set()
        q = deque()

        ROWS, COLS = len(grid), len(grid[0])
        dirs = {(0, -1), (-1, 0), (0, 1), (1, 0)}

        for i in range(ROWS):
            for j in range(COLS):
                if grid[i][j] == 1:
                    fresh.add((i, j))
                elif grid[i][j] == 2:
                    q.append((i, j))

        steps = 0

        while q and fresh:
            tempQ = q
            q = deque()

            while tempQ:
                i, j = tempQ.popleft()

                for row, col in dirs:
                    nRow = row + i
                    nCol = col + j

                    if not ((0 <= nRow < ROWS and 0 <= nCol < COLS) and grid[nRow][nCol] == 1):
                        continue

                    grid[nRow][nCol] = 2
                    fresh.remove((nRow, nCol))
                    q.append((nRow, nCol))

            steps += 1

        return steps if len(fresh) == 0 else -1