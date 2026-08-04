/* ## Brute Force Approach

### Intuition
The idea is to first separate all positive and negative numbers into two
different vectors. Since the problem guarantees that the number of positive and
negative elements is equal, we can simply traverse both vectors together and
insert one positive element followed by one negative element into the answer
vector.

Although this approach is simple and easy to understand, it requires two
additional vectors to store the positive and negative numbers before
constructing the final result.

### Algorithm
1. Create two vectors:
   - `positive` to store all positive numbers.
   - `negative` to store all negative numbers.
2. Traverse the input array:
   - If the current element is positive, store it in `positive`.
   - Otherwise, store it in `negative`.
3. Traverse both vectors simultaneously.
4. Insert one positive element followed by one negative element into the answer
vector.
5. Return the final rearranged array.

### Dry Run

**Input:**
```text
nums = [3, 1, -2, -5, 2, -4]
```

After separating:

```text
positive = [3, 1, 2]
negative = [-2, -5, -4]
```

Construct the answer:

```text
ans = [3]
ans = [3, -2]
ans = [3, -2, 1]
ans = [3, -2, 1, -5]
ans = [3, -2, 1, -5, 2]
ans = [3, -2, 1, -5, 2, -4]
```

**Output:**

```text
[3, -2, 1, -5, 2, -4]
```

### Complexity Analysis

- **Time Complexity:** `O(n)`
  - One traversal to separate the elements.
  - One traversal to merge both vectors.

- **Space Complexity:** `O(n)`
  - Extra space is used for the `positive`, `negative`, and `answer` vectors.
  */
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> positive;
        vector<int> negative;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                positive.push_back(nums[i]);
            } else {
                negative.push_back(nums[i]);
            }
        }

        for (int i = 0; i < positive.size(); i++) {
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }
        return ans;
    }
};