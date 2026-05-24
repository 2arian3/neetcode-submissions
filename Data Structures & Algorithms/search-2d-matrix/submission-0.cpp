class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int cols = matrix[0].size();

        while (top <= bottom) {
            int midRow = top + (bottom - top) / 2;

            if (target < matrix[midRow][0]) {
                bottom = midRow - 1;
            }
            else if (target > matrix[midRow][cols - 1]) {
                top = midRow + 1;
            }
            else {
                int left = 0;
                int right = cols - 1;

                while (left <= right) {
                    int mid = left + (right - left) / 2;

                    if (matrix[midRow][mid] == target) {
                        return true;
                    }
                    else if (matrix[midRow][mid] < target) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }

                return false;
            }
        }

        return false;
    }
};