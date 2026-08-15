// LeetCode 1283 - Smallest Divisor Given a Threshold
//
// Pattern: Binary Search on Answer
//
// Idea:
// Find the smallest divisor such that
// sum of ceil(nums[i] / divisor) <= threshold.
//
// Search Space:
// low = 1
// high = max(nums)
//
// For every mid:
//     Calculate sum using mid as divisor.
//
// If sum <= threshold:
//     mid is valid → search LEFT
//     high = mid - 1
//
// Else:
//     mid is too small → search RIGHT
//     low = mid + 1
//
// Why Binary Search?
// Smaller divisor → larger sum
// Larger divisor  → smaller sum

// Important:
// ceil(a / b) can be calculated as:
// (a + b - 1) / b
//
// In the given code, ceil(double(a)/double(b))
// also works.
//
// After binary search:
// low = smallest valid divisor
//
// Time: O(n log(max(nums)))
// Space: O(1)

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int high = *max_element(nums.begin(), nums.end());
        int low = 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += ceil(double(nums[i]) / double(mid));
            }
            if (sum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};