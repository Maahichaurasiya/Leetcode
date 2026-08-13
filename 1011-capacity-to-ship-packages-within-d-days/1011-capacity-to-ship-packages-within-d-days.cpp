// TC=>O(n log(sum(weights)))
// SC=>O(1)

class Solution {
public:
    int sum(vector<int>& weights) {
        int s = 0;
        for (int i = 0; i < weights.size(); i++) {
            s += weights[i];
        }
        return s;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = sum(weights);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int daysUsed = 1;
            int currWeight = 0;
            for (int i = 0; i < weights.size(); i++) {
                if (currWeight + weights[i] > mid) {
                    daysUsed++;
                    currWeight = 0;
                }
                currWeight += weights[i];
            }
            if (daysUsed <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};