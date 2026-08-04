/*## Optimized Approach

### Intuition

In the brute force approach, we first store positive and negative numbers in two
separate vectors and then merge them. This requires extra work.

Observe that:
- Positive numbers always go to **even indices** (`0, 2, 4, ...`).
- Negative numbers always go to **odd indices** (`1, 3, 5, ...`).

So, instead of storing them separately, we can directly place each element into
its correct position while traversing the array only once.

### Algorithm

1. Create an answer vector of size `n`.
2. Set `positiveIndex = 0` and `negativeIndex = 1`.
3. Traverse the array:
   - If the element is positive, place it at `positiveIndex` and move
`positiveIndex` by `2`.
   - Otherwise, place it at `negativeIndex` and move `negativeIndex` by `2`.
4. Return the answer vector.

### Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int posIndex = 0;
        int negIndex = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans[posIndex] = nums[i];
                posIndex += 2;
            } else {
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
        }
        return ans;
    }
};