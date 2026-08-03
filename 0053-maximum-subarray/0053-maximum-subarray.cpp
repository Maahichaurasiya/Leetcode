/*
---------------------------------------------------------
Approach: Kadane's Algorithm (Optimal)
---------------------------------------------------------

Intuition:
The main idea is to keep track of the sum of the current
contiguous subarray. As we iterate through the array, we
keep adding the current element to the running sum.

If this running sum becomes negative, it cannot contribute
to a larger subarray in the future because adding a negative
sum will only decrease the total. So, we simply discard it
and start a new subarray from the next element.

At every step, we compare the current sum with the maximum
sum found so far and update the answer if needed.

Why does this work?
- A positive running sum can help increase the sum of future
  elements, so we keep it.
- A negative running sum will only reduce the total of any
  future subarray, so it's better to start fresh.

Algorithm:
1. Initialize 'currSum' as 0 and 'maxSum' as INT_MIN.
2. Traverse the array once.
3. Add the current element to 'currSum'.
4. Update 'maxSum' if 'currSum' is greater.
5. If 'currSum' becomes negative, reset it to 0.
6. After the traversal, return 'maxSum'.

Time Complexity: O(n)
- We traverse the array only once.

Space Complexity: O(1)
- No extra space is used apart from a few variables.

Note:
This is the optimal solution for the Maximum Subarray problem
and is known as Kadane's Algorithm.
---------------------------------------------------------
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += nums[i];
            maxSum = max(currSum, maxSum);
            if (currSum < 0) {
                currSum = 0;
            }
        }
        return maxSum;
    }
};