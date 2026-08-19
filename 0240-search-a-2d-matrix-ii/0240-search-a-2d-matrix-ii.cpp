class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size();
        int cols = mat[0].size();
        for (int i = 0; i < rows; i++) {
            int low = 0;
            int high = cols - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (mat[i][mid] == target) {
                    return true;
                } else if (mat[i][mid] > target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return false;
    }
};