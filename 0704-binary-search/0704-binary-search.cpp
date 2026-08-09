// Iterative Binary Search

// We use a while loop to search for the target.
//
// 1. Set st = 0 and end = n - 1.
// 2. Find the middle element.
// 3. If nums[mid] == target, return mid.
// 4. If nums[mid] < target, move st to mid + 1.
// 5. Otherwise, move end to mid - 1.
// 6. Continue until st > end.
// 7. If target is not found, return -1.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0;
        int end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }
};