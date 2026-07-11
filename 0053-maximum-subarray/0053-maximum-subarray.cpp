class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;// Initialize to lowest possible integer to handle all-negative arrays
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            maxSum = max(maxSum, currSum); // Record the peak sum found so far

            if (currSum < 0) {
            currSum=0;
            }
        }
        
        return maxSum;
    }
};