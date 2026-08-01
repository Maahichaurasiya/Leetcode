
    /*

    Approach: Better (Sorting + Two Pointers)

    Idea:
    - The brute force approach checks every possible pair, which takes O(N²)
    time.
    - To improve this, store each element along with its original index.
    - Sort the elements based on their values.
    - Use two pointers:
        • Left pointer starts from the beginning.
        • Right pointer starts from the end.
    - Compare the sum of the two elements:
        • If the sum equals the target, return their original indices.
        • If the sum is smaller than the target, move the left pointer forward.
        • If the sum is greater than the target, move the right pointer backward


    Algorithm:
    1. Store each element with its original index.
    2. Sort the vector according to the values.
    3. Initialize two pointers:
          i = 0
          j = n - 1
    4. While i < j:
          - If sum == target, return the original indices.
          - If sum < target, move i++.
          - Otherwise, move j--.
    5. If no valid pair is found, return an empty vector.

    Time Complexity:
    - Sorting: O(N log N)
    - Two Pointer Traversal: O(N)
    - Overall: O(N log N)

    Space Complexity:
    - O(N)
      (Extra space is used to store value-index pairs.)
 */

    class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            ans.push_back({nums[i], i});
        }
        sort(ans.begin(), ans.end());

        int left = 0;
        int right = n - 1;
        while (left < right) {
            int sum = ans[left].first + ans[right].first;
            if (sum == target) {
                return {ans[left].second, ans[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};