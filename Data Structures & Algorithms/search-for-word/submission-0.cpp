class Solution {
private:
    int ROWS, COLS;

public:
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        for (int i = 0; i < ROWS; i++)
            for (int j = 0; j < COLS; j++)
                if (dfs(board, word, i, j, 0))
                    return true;

        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int i) {
        if (i == word.size())
            return true;
        
        if (row >= ROWS || col >= COLS || row < 0 || col < 0
            || board[row][col] != word[i] || board[row][col] == '*')
            return false;
        
        board[row][col] = '*';
        bool result = dfs(board, word, row + 1, col, i + 1) ||
                      dfs(board, word, row, col + 1, i + 1) ||
                      dfs(board, word, row - 1, col, i + 1) ||
                      dfs(board, word, row, col - 1, i + 1);
        board[row][col] = word[i];

        return result;
    }
};
