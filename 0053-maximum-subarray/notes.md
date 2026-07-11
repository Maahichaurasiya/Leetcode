## 💡 Core Intuition
This problem utilizes **Kadane's Algorithm**, which uses a greedy strategy to find the maximum subarray sum in a single pass. 

The core realization is that we should only maintain a running subarray sum as long as it contributes positively to our total. If `currSum` drops below `0`, it becomes a net negative. Any future numbers added to it will result in a smaller sum than if those future numbers just started a brand-new subarray on their own.

By updating `maxSum` *before* resetting `currSum` to `0`, we guarantee that even if the array is composed entirely of negative numbers, we still accurately capture the single largest negative value.

## ⚙️ C++ Specific Details
- **`INT_MIN` Initialization:** Initializing `maxSum` to `INT_MIN` (from the `<climits>` header) ensures that any valid integer in the array will override it on the first comparison, preventing errors with strictly negative datasets.
- **Pass-by-Reference:** Accepting `vector<int>& nums` by reference prevents an expensive $O(n)$ data-copying operation.
- **`std::max` Efficiency:** Using the built-in `std::max` function allows the compiler to optimize the conditional check down to a highly efficient assembly instruction.

## 🛑 Edge Cases Handled
- **Single Element Arrays:** If `nums = [-5]`, `currSum` becomes `-5`, `maxSum` updates from `INT_MIN` to `-5`, `currSum` resets to `0`, and the loop finishes. Returns `-5` (Correct).
- **All Negative Values:** e.g., `[-3, -2, -4]`. The algorithm tracks the peak (`-2`), safely ignoring the reset logic until *after* the global maximum is recorded.

## 📊 Complexity
- **Time Complexity:** $O(n)$ — A single linear scan through the vector elements.
- **Space Complexity:** $O(1)$ — Only two scalar integer tracking variables (`maxSum`, `currSum`) are allocated in memory.
