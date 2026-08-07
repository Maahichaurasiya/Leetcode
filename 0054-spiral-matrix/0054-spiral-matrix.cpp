// Approach: Spiral Traversal
//
// Use 4 boundaries:
// srow = starting row
// erow = ending row
// scol = starting column
// ecol = ending column
//
// Traverse in 4 directions:
// 1. Top    → left to right
// 2. Right  → top to bottom
// 3. Bottom → right to left
// 4. Left   → bottom to top
//
// After one complete layer, move boundaries inward:
// srow++, erow--, scol++, ecol--
//
// Extra checks avoid visiting the same element twice
// when there is only one row or one column.
//
// Time: O(m × n)
// Space: O(m × n) for the answer vector

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0;
        int erow = m - 1;
        int scol = 0;
        int ecol = n - 1;

        while (srow <= erow && scol <= ecol) {
            // top
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }

            // right
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            // bottom
            for (int j = ecol - 1; j >= scol; j--) {
                if (srow == erow) {
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }

            // left
            for (int i = erow - 1; i >= srow + 1; i--) {
                if (scol == ecol) {
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }
            srow++;
            erow--;
            scol++;
            ecol--;
        }

        return ans;
    }
};