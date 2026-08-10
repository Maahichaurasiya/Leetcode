/*
approach-(bruteForce using linear search)
Problem:
Find the element that appears only once in a sorted array.
Every other element appears exactly twice.

Approach:
- Traverse the array from left to right.
- Check the first and last elements separately.
- For middle elements, compare with both neighbors.
- If an element is different from both neighbors, it is the single element.
- Return -1 if no such element is found.

Time Complexity: O(n)
Space Complexity: O(1)

Note:
This is the simple linear-search approach.
The problem can also be optimized to O(log n) using Binary Search.
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (nums[i] != nums[i + 1]) {
                    return nums[i];
                }
            } else if (i == (n - 1)) {
                if (nums[i] != nums[i - 1]) {
                    return nums[i];
                }
            } else {
                if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
                    return nums[i];
                }
            }
        }
        return -1;
    }
};