/*
-----------------------------------------------
Approach: Brute Force (Bubble Sort)
-----------------------------------------------

Algorithm:
1. Traverse the array multiple times.
2. Compare each element with its adjacent element.
3. If the current element is greater than the next element, swap them.
4. After each pass, the largest unsorted element moves to its correct position.
5. Repeat the process until the entire array is sorted.

Example:
Input:  [2, 0, 2, 1, 1, 0]
Pass 1: [0, 2, 1, 1, 0, 2]
Pass 2: [0, 1, 1, 0, 2, 2]
Pass 3: [0, 1, 0, 1, 2, 2]
Pass 4: [0, 0, 1, 1, 2, 2]

Time Complexity: O(n²)
- Nested loops are used to compare and swap elements.

Space Complexity: O(1)
- Sorting is performed in-place without using extra memory.

This is a simple sorting approach but is inefficient for large arrays.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
    }
};