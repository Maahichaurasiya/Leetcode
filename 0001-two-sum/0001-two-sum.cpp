/*
Approach: Brute Force


Algorithm:
1. Traverse the array using index 'i'.
2. For each element, traverse the remaining elements using index 'j = i + 1'.
3. Check if:
       nums[i] + nums[j] == target
4. If true, return {i, j}.
5. If no valid pair is found, return an empty vector.


Time Complexity:
- O(N²)
  (Two nested loops check every possible pair.)

Space Complexity:
- O(1)
  (No extra data structure is used.)

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        
        return {};
    }
};