class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Minimum possible eating speed
        int low = 1;

        // Maximum possible eating speed
        int high = *max_element(piles.begin(), piles.end());

        // Store the minimum valid speed found so far
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long total_h = 0;
            for (int k : piles) {
                // k is banana
                // ceil(bananas / mid)
                total_h += (k + mid - 1) / mid;
            }
            // If Koko can finish within h hours
            if (total_h <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Return the minimum possible eating speed
        return ans;
    }
};