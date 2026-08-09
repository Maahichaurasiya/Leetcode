
// Approach:
// Use Binary Search to find the first position where nums[i] >= target.
//
// If nums[mid] >= target:
// → Move left: end = mid - 1
//
// If nums[mid] < target:
// → Move right: st = mid + 1
//
// When the loop ends, `st` is the correct insert position.
//
// This is basically the Lower Bound pattern.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] >= target) {
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        return st;
    }
};