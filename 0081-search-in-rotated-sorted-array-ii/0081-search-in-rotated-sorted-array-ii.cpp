// optimal approach

// Key idea:
// The array is sorted but rotated, and duplicates may be present.
//
// 1. Find mid.
// 2. If nums[mid] == target:
//      Target found → return true.
//
// 3. If nums[st] == nums[mid] == nums[end]:
//      We cannot identify which half is sorted.
//      So shrink both sides:
//      st++;
//      end--;
//
// 4. If left half is sorted:
//      Check whether target lies in the left half.
//      If yes → move end to mid - 1.
//      Otherwise → move st to mid + 1.
//
// 5. Otherwise, right half is sorted:
//      Check whether target lies in the right half.
//      If yes → move st to mid + 1.
//      Otherwise → move end to mid - 1.
//
// Time Complexity:
// Average: O(log n)
// Worst:   O(n) because of duplicates
//
// Space Complexity:
// O(1)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int st = 0, end = n - 1;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return true;
            }

            // if duplicate elements are present

            if (nums[st] == nums[mid] && nums[mid] == nums[end]) {
                st++;
                end--;
            }

            // left half is sorted
            else if (nums[st] <= nums[mid]) {
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
        return false;
    }
};