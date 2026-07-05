class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows, cols;
        map<pair<int, int>, unordered_set<int>> sqs;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.')
                    continue;

                int num = board[i][j] - '0';
                int x = i / 3;
                int y = j / 3;
                if (rows[i].contains(num) || cols[j].contains(num) || sqs[{x, y}].contains(num))
                    return false;
                
                rows[i].insert(num);
                cols[j].insert(num);
                sqs[{x, y}].insert(num);
            }
        }

        return true;
    }
};
