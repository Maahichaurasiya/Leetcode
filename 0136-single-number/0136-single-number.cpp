/*
------------------------------------------------------------
Approach: XOR (Optimal Solution)

Idea:
- The XOR (^) operator is used to find the element that appears only once.
- Every element in the array appears twice except one.

Properties of XOR:
1. a ^ a = 0      -> Same numbers cancel each other.
2. a ^ 0 = a      -> XOR with 0 returns the same number.
3. XOR is commutative and associative, so order does not matter.

Algorithm:
1. Initialize ans = 0.
2. Traverse the entire array.
3. Perform ans = ans ^ nums[i] for every element.
4. All duplicate elements become 0 after XOR.
5. The remaining value in ans is the single occurring element.
6. Return ans.

Example:
nums = [4, 1, 2, 1, 2]

ans = 0
0 ^ 4 = 4
4 ^ 1 = 5
5 ^ 2 = 7
7 ^ 1 = 6
6 ^ 2 = 4

Output: 4

Time Complexity: O(n)
- The array is traversed only once.

Space Complexity: O(1)
- Only one extra variable (ans) is used.

------------------------------------------------------------
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};