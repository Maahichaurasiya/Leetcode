/*## Approach (Optimal)

* Traverse the array only once.
* Maintain two variables:

  * `count` → stores the current consecutive count of `1`s.
  * `maxCount` → stores the maximum consecutive `1`s found so far.
* If the current element is `1`, increment `count` and update `maxCount`.
* If the current element is `0`, reset `count` to `0` because the consecutive
sequence is broken.
* After traversing the array, return `maxCount`.

### Time Complexity

* **O(n)** – The array is traversed only once.

### Space Complexity

* **O(1)** – Only two extra variables are used.

### Key Idea

Keep track of the **current streak** of consecutive `1`s and continuously update
the **maximum streak** encountered during the traversal.

*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count += 1;
                maxCount = max(maxCount, count);
            } else {
                count = 0;
            }
        }
        return maxCount;
    }
};