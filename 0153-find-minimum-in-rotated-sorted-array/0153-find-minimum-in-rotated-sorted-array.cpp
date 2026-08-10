// Find Minimum in Rotated Sorted Array
//
// Key Idea:
// The array is sorted but rotated.
// Use binary search to find the rotation point.
//
// 1. Find mid.
// 2. Compare nums[mid] with nums[end].
//
// If nums[mid] > nums[end]:
//     Minimum is on the right.
//     st = mid + 1
//
// Otherwise:
//     Minimum is at mid or on the left.
//     end = mid
//
// We use end = mid instead of mid - 1
// because mid itself can be the minimum.
//
// Loop ends when st == end.
// nums[st] is the minimum.
//
// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0, end = n - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] > nums[end]) {
                st = mid + 1;
            } else {
                end = mid;
            }
        }
        return nums[st];
    }
};