/*
Approach:
---------
Use two pointers.

- i     -> Traverses the entire array.
- index -> Points to the position where the next
           non-zero element should be placed.

First, copy all non-zero elements to the front of
the array.

After placing all non-zero elements, fill the
remaining positions with 0.

This maintains the relative order of non-zero
elements while moving all zeroes to the end.

Algorithm:
----------
1. Initialize index = 0.
2. Traverse the array.
3. If nums[i] is not 0:
      - nums[index] = nums[i]
      - index++
4. After traversal, fill the remaining positions
   with 0.
5. The array is now modified in-place.

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

Pattern:
--------
Two Pointers (Same Direction)
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[index] = nums[i];
                index++;
            }
        }
        while (index < n) {
            nums[index] = 0;
            index++;
        }
    }
};