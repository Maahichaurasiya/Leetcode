// Search in Rotated Sorted Array
//
// The array is originally sorted but rotated at some position.
// Example: [4,5,6,7,0,1,2]
//
// Normal binary search cannot be directly used because the
// entire array is not sorted.
//
// But at every step, at least one half is always sorted.
//
// Steps:
// 1. Find the middle element.
// 2. If nums[mid] == target, return mid.
// 3. Check which half is sorted.
// 4. If left half is sorted:
//      - Check if target lies between nums[st] and nums[mid].
//      - If yes, search left half.
//      - Otherwise, search right half.
// 5. If right half is sorted:
//      - Check if target lies between nums[mid] and nums[end].
//      - If yes, search right half.
//      - Otherwise, search left half.
// 6. If target is not found, return -1.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            // left half is sorted
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target < nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }

            }

            // right half is sorted
            else {
                if (nums[mid] < target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};