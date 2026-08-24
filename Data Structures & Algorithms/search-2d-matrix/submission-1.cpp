class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for (int row = 0; row < matrix.size(); row++) {
            int high = matrix[0].size() -1;

            if (matrix[row][high] < target) {
                continue; 
            } else {
                int low = 0;
                while (low <= high) {
                    int mid = low + ((high-low)/2);
                    if (matrix[row][mid] < target) {
                        low = mid + 1;
                    } else if (matrix[row][mid] > target) {
                        high = mid - 1;
                    } else {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
