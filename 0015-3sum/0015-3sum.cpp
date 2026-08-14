// Three Sum — GitHub Short Notes
//
// Goal:
// Find all unique triplets [a, b, c] such that:
// a + b + c = 0
//
// Approach:
// 1. Sort the array.
// 2. Fix one element using index i.
// 3. Use two pointers:
//      j = i + 1
//      k = n - 1
// 4. Check nums[i] + nums[j] + nums[k]:
//      sum < 0  -> j++
//      sum > 0  -> k--
//      sum == 0 -> store triplet and move both pointers.
//
// Duplicate Handling:
// - Skip duplicate nums[i] to avoid repeated triplets.
// - After finding a valid triplet, skip duplicate nums[j].
//
// Why sorting?
// - Makes the two-pointer approach possible.
// - Helps handle duplicates easily.
//
// Time Complexity:
// O(n log n) for sorting + O(n²) for two pointers
// Overall: O(n²)
//
// Space Complexity:
// O(1) extra space (excluding the answer vector).
//
// Pattern:
// Sorting + Two Pointers
//
// Key Idea:
// Fix one element and find the remaining two elements
// using the Two Pointer technique.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            
            if(i>0 && nums[i]==nums[i-1]) continue;

            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0) {
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;

                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                }
            }
        }
        return ans;
    }

            
};