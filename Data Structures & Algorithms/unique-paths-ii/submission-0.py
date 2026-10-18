class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        ROWS, COLS = len(obstacleGrid), len(obstacleGrid[0])

        if obstacleGrid[0][0] or obstacleGrid[ROWS - 1][COLS - 1]:
            return 0

        obstacleGrid[0][0] = 1

        for i in range(ROWS):
            for j in range(COLS):
                if (i, j) == (0, 0):
                    continue

                if obstacleGrid[i][j]:
                    obstacleGrid[i][j] = 0
                    continue

                up = 0 if i == 0 else obstacleGrid[i - 1][j]
                left = 0 if j == 0 else obstacleGrid[i][j - 1]

                obstacleGrid[i][j] = up + left


        return obstacleGrid[ROWS - 1][COLS - 1]