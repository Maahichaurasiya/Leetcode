// Approach:
// 1. Sort the array.
// 2. Majority element (> n/2 occurrences) will always be at index n/2.
// 3. Return nums[n/2].

// Time Complexity: O(n log n)
// Space Complexity: O(log n) (recursion stack of std::sort)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n/2];

    
    }
};