// Recursive Binary Search
//
// Approach:
// 1. Find the middle element.
// 2. If nums[mid] == target, return mid.
// 3. If nums[mid] < target, search in the right half.
// 4. If nums[mid] > target, search in the left half.
// 5. If st > end, target is not present.
//
// Base Case:
// st > end → return -1
//
// Time Complexity: O(log n)
// Space Complexity: O(log n) due to recursion
//
// Important: Array must be sorted.

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int st, int end) {
        if (st > end) {
            return -1;
        }
        int mid = st + (end - st) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return binarySearch(nums, target, mid + 1, end);
        }

        else {
            return binarySearch(nums, target, st, mid - 1);
        }
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};