/*
Approach:
---------
Use the Reverse Algorithm to rotate the array in-place.

Steps:
1. Find the effective rotations using k = k % n.
2. Reverse the entire array.
3. Reverse the first k elements.
4. Reverse the remaining (n-k) elements.

After these three reversals, the array becomes
rotated to the right by k positions.

Algorithm:
----------
1. n = nums.size()
2. k = k % n
3. Reverse the whole array.
4. Reverse the first k elements.
5. Reverse the remaining elements.

Why k = k % n?
--------------
If k is greater than the array size, rotating k times
is the same as rotating (k % n) times.

Example:
n = 7, k = 10

10 % 7 = 3

So, rotate only 3 times.

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

Pattern:
--------
Array Manipulation
Reverse Algorithm
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};