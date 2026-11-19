class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        SIZE = 9

        row_digits = {i: set() for i in range(SIZE)}
        col_digits = {i: set() for i in range(SIZE)}
        box_digits = {i: set() for i in range(SIZE)}
        get_box_num = lambda row, col: 3 * (row // 3) + col // 3

        
        for row in range(SIZE):
            for col in range(SIZE):
                digit = board[row][col]
                box_num = get_box_num(row, col)

                if digit == ".":
                    continue

                if digit in row_digits[row] or digit in col_digits[col] or digit in box_digits[box_num]:
                    return False

                row_digits[row].add(digit)
                col_digits[col].add(digit)
                box_digits[box_num].add(digit)
        
        return True