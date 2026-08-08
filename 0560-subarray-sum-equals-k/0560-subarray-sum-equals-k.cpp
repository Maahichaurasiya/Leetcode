// Approach: Prefix Sum + HashMap
//
// Prefix Sum = sum of elements from the beginning till current index.
//
// Main idea:
// currentSum - previousSum = k
//
// So,
// previousSum = currentSum - k
//
// Steps:
// 1. Calculate prefix sum for each index.
// 2. Store prefix sums and their frequency in a HashMap.
// 3. For every current prefix sum:
//    - If currentSum == k, count one subarray.
//    - Find (currentSum - k) in the map.
//    - If found, add its frequency to count.
// 4. Store the current prefix sum in the map.
//
// Why frequency?
// The same prefix sum can appear multiple times,
// and each occurrence can form a different subarray.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        unordered_map<int, int> m; // prefix sum,frequency
        for (int j = 0; j < n; j++) {
            if (prefixSum[j] == k) {
                count++;
            }
            int val = prefixSum[j] - k;
            if (m.find(val) != m.end()) {
                count += m[val];
            }
            if (m.find(prefixSum[j]) == m.end()) {
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }

        return count;
    }
};