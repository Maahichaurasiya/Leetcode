/*
------------------------------------------------------------
Dutch National Flag Algorithm
------------------------------------------------------------

The Dutch National Flag Algorithm is an efficient algorithm used to
partition an array containing three distinct values into three separate
regions in a single traversal.

It uses three pointers:

1. low  -> Marks the boundary for the next smallest element.
2. mid  -> Traverses the array and processes each element.
3. high -> Marks the boundary for the next largest element.

Initially:
low = 0
mid = 0
high = n - 1

During execution, the array is divided into four regions:

--------------------------------------------------------
0 to low-1        -> Elements in the first region
low to mid-1      -> Elements in the second region
mid to high       -> Unprocessed elements
high+1 to n-1     -> Elements in the third region
--------------------------------------------------------

Working:

1. If the current element belongs to the first region:
   - Swap it with the element at 'low'.
   - Increment both 'low' and 'mid'.

2. If the current element belongs to the second region:
   - It is already in the correct position.
   - Increment only 'mid'.

3. If the current element belongs to the third region:
   - Swap it with the element at 'high'.
   - Decrement 'high'.
   - Do NOT increment 'mid' because the new element brought
     from the end has not been processed yet.

The process continues until 'mid' becomes greater than 'high'.


Time Complexity: O(n)
Space Complexity: O(1)


*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int mid = 0;
        int high = n - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low = low + 1;
                mid = mid + 1;
            } else if (nums[mid] == 1) {
                mid = mid + 1;
            } else {
                // nums[mid]==2
                swap(nums[mid], nums[high]);
                high = high - 1;
            }
        }
    }
};