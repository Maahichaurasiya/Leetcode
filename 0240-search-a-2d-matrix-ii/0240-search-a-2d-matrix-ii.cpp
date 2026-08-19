
// Approach: Staircase Search (Optimal)
//
// Idea:
// - Each row is sorted left → right.
// - Each column is sorted top → bottom.
// - Start from the top-right corner.
//
// If matrix[i][j] > target:
//     Move LEFT (j--)
//     Because all elements below are even larger.
//
// If matrix[i][j] < target:
//     Move DOWN (i++)
//     Because all elements on the left are smaller.
//
// If matrix[i][j] == target:
//     Return true.
//
// If we reach outside the matrix, target doesn't exist.
//
// Time: O(rows + cols)
// Space: O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row = mat.size();
        int col = mat[0].size();
        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (mat[i][j] == target) {
                return true;
            } else if (mat[i][j] > target) {
                j--;
            } else {
                i++;
            }
        }

        return false;
    }
};