

// Approach:
// Use Binary Search twice.
//
// 1. findFirst()
//    - If target is found, store index in ans.
//    - Move left using end = mid - 1 to find an earlier occurrence.
//
// 2. findLast()
//    - If target is found, store index in ans.
//    - Move right using st = mid + 1 to find a later occurrence.
//
// Binary Search conditions:
// nums[mid] < target → st = mid + 1
// nums[mid] > target → end = mid - 1
//
// If target is not present, ans remains -1.
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                ans = mid;
                end = mid - 1;

            } else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        int ans = -1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                ans = mid;
                st = mid + 1;

            } else if (nums[mid] < target) {
                st = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};