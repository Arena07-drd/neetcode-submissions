class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0;
        int right = matrix[0].size() - 1;
        int up = 0;
        int down = matrix.size() - 1;
        int midRow;

        while (up <= down) {
            midRow = up + ((down-up)/2);

            if (matrix[midRow][right] < target) {
                up = midRow + 1;
            } else if (matrix[midRow][left] > target) {
                down = midRow - 1;
            } else {
                break;
            }
        }

        int midCol;
        while (left <= right) {
            midCol = left + ((right-left)/2);

            if (matrix[midRow][midCol] < target) {
                left = midCol + 1;
            } else if (matrix[midRow][midCol] > target) {
                right = midCol - 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
