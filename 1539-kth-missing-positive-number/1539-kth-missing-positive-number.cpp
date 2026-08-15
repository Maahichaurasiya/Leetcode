
// Pattern: Binary Search
//
// missing = arr[i] - (i + 1)
// → tells how many numbers are missing before arr[i].
//
// If missing < k:
//     Need more missing numbers → RIGHT
//     low = mid + 1
//
// Else:
//     Enough missing numbers → LEFT
//     high = mid - 1
//
// After search:
//     answer = low + k
//
// Example:
// arr = [2,3,4,7,11], k = 5
// Answer = 9
//
// Time: O(log n)
// Space: O(1)

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low + k;
    }
};