class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int low = 0;
        int high = rows - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // Find maximum element in middle row
            int maxCol = 0;
            for (int j = 1; j < cols; j++) {
                if (mat[mid][j] > mat[mid][maxCol]) {
                    maxCol = j;
                }
            }
            // Current element
            int curr = mat[mid][maxCol];
            // Up and Down values
            int up = (mid > 0) ? mat[mid - 1][maxCol] : -1;
            int down = (mid < rows - 1) ? mat[mid + 1][maxCol] : -1;
            // Peak found
            if (curr > up && curr > down) {
                return {mid, maxCol};
            }
            // Down is bigger → search bottom half
            else if (down > curr) {
                low = mid + 1;
            }
            // Up is bigger → search top half
            else {
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};