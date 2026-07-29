/*
Approach:
---------
A sorted array has elements in increasing order.

After rotating the array, there can be only ONE place
where the order decreases.

Example:
[3,4,5,1,2]

3 < 4 ✓
4 < 5 ✓
5 > 1 ✗ (1 break)
1 < 2 ✓
2 < 3 ✓ (last compared with first)

Count how many times:
nums[i] > nums[(i+1)%n]

If the count is:
- 0 → Already sorted
- 1 → Sorted and rotated
- More than 1 → Not sorted and rotated

Algorithm:
----------
1. Initialize count = 0.
2. Traverse the array.
3. If nums[i] > nums[(i+1)%n], increment count.
4. Return true if count <= 1, otherwise false.

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

Pattern:
--------
Array Traversal
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        return count <= 1;
    }
};