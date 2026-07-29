/*
Approach (Hashing):
------------------
Use an unordered_set to store unique elements.

Traverse the array:
1. If the current element is not in the set,
   insert it into the set.
2. Place the unique element at nums[index].
3. Increment index.

At the end, index represents the number of
unique elements.

Time Complexity:
O(n)

Space Complexity:
O(n)

Pattern:
--------
Hashing (unordered_set)
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        unordered_set<int> st;
        int index = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (st.find(nums[i]) == st.end()) {

                st.insert(nums[i]);
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};