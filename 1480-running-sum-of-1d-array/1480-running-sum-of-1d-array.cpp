/*
Approach:
---------
We need to find the running sum of the array.

The running sum means that every element stores the sum of itself
and all the previous elements.

Instead of calculating the sum from the beginning every time,
we keep a variable `sum` that stores the running total..

Algorithm:
----------
1. Create an empty vector `ans`.
2. Initialize `sum = 0`.
3. Traverse the array from left to right.
4. Add the current element to `sum`.
5. Push `sum` into the answer vector.
6. Return the answer vector.



Time Complexity:
----------------
O(n)
We traverse the array only once.

Space Complexity:
-----------------
O(n)
An extra vector is used to store the running sums.
*/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            ans.push_back(sum);
        }
        return ans;
    }
};