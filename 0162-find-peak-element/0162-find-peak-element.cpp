class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // If there is only one element, it is a peak
        if (n == 1) {
            return 0;
        }
        // Check first element
        if (nums[0] > nums[1]) {
            return 0;
        }
        // check last element
        if (nums[n - 1] > nums[n - 2]) {
            return n - 1;
        }

        // checks mid element
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i + 1] && nums[i] > nums[i - 1]) {
                return i;
            }
        }
        return -1;
    }
};