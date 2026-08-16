class Solution {
private:
    int N;
    vector<vector<string>> res;
public:
    vector<vector<string>> solveNQueens(int n) {
        N = n;
        vector<string> board(n, string(n, '.'));

        unordered_set<int> filledCols;
        unordered_set<int> positiveDiag;    //for same row+col
        unordered_set<int> negativeDiag;    //for same row-col

        backtrack(board, 0, filledCols, positiveDiag, negativeDiag);

        return res;
    }

    void backtrack(vector<string>& board, int row, unordered_set<int>& filledCols, unordered_set<int>& positiveDiag, unordered_set<int>& negativeDiag) {
        if (row >= N) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < N; col++) {
            if (filledCols.contains(col) || positiveDiag.contains(row+col) || negativeDiag.contains(row-col))
                continue;
            board[row][col] = 'Q';
            filledCols.insert(col);
            positiveDiag.insert(row+col);
            negativeDiag.insert(row-col);
            backtrack(board, row + 1, filledCols, positiveDiag, negativeDiag);

            board[row][col] = '.';
            filledCols.erase(col);
            positiveDiag.erase(row+col);
            negativeDiag.erase(row-col);
        }

        return;
    }
};
