/*
Approach:
---------
The array is sorted, so duplicate elements are next to each other.

Use two pointers:
- index -> points to the last unique element.
- i     -> checks every element.

If nums[i] is different from nums[index]:
1. Move index forward.
2. Copy nums[i] to nums[index].

At the end, the first (index + 1) elements are the unique elements.

Algorithm:
----------
1. Set index = 0.
2. Traverse the array from i = 1 to n-1.
3. If nums[i] != nums[index]:
   - index++
   - nums[index] = nums[i]
4. Return index + 1.

Time Complexity:
----------------
O(n)

Space Complexity:
-----------------
O(1)

Pattern:
--------
Two Pointers (Same Direction)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[index]){
                index++;
                nums[index]=nums[i];
            }
        }
        return index+1;

    }
};