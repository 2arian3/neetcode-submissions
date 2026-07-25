class Solution {
private:
    int ROWS, COLS;
public:
    void solve(vector<vector<char>>& board) {
        ROWS = board.size();
        COLS = board[0].size();
        
        for (int i = 0; i < ROWS; i++) {
            if (board[i][0] == 'O')
                capture(board, i, 0);
            if (board[i][COLS-1] == 'O')
                capture(board, i, COLS-1);
        }

        for (int i = 0; i < COLS; i++) {
            if (board[0][i] == 'O')
                capture(board, 0, i);
            if (board[ROWS-1][i] == 'O')
                capture(board, ROWS-1, i);
        }

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'C')
                    board[i][j] = 'O';
            }
        }
    }

    void capture(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS ||
            board[row][col] != 'O')
            return;
        
        board[row][col] = 'C';

        capture(board, row - 1, col);
        capture(board, row + 1, col);
        capture(board, row, col + 1);
        capture(board, row, col - 1);
    }
};
