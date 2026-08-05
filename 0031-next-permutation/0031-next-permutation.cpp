/*
------------------------------------------------------------
Approach: Next Permutation (Optimal)
------------------------------------------------------------

Idea:
The goal is to find the next lexicographically greater permutation
of the given array.

Key Observation:
- The longest suffix that is in descending order is already the
  largest possible arrangement.
- To get the next permutation, we need to make a small increase
  just before this suffix.

Algorithm:
1. Traverse the array from right to left and find the first index
   where A[i] < A[i + 1].
   This index is called the "pivot".

2. If no such index exists, the array is completely in descending
   order, which means it is already the largest permutation.
   Reverse the entire array to get the smallest permutation.

3. Otherwise, traverse from the end of the array and find the
   first element greater than the pivot element.
   Swap this element with the pivot.

4. After swapping, the suffix is still in descending order.
   Reverse the suffix to convert it into ascending order,
   giving the smallest possible suffix.

Why does this work?
- Swapping with the rightmost greater element makes the number
  just slightly larger.
- Reversing the suffix ensures the remaining elements are arranged
  in the smallest possible order.
- This guarantees the immediate next lexicographical permutation.

Example:
Input:
1 2 3 6 5 4

Pivot = 3

Swap 3 and 4:
1 2 4 6 5 3

Reverse suffix:
1 2 4 3 5 6

Output:
1 2 4 3 5 6

Time Complexity:
O(n)
- Find pivot: O(n)
- Find next greater element: O(n)
- Reverse suffix: O(n)

Space Complexity:
O(1)
- In-place algorithm with constant extra space.
------------------------------------------------------------
*/
class Solution {
public:
    void nextPermutation(vector<int>& A) {
        // find pivot element
        int pivot = -1;
        int n = A.size();
        for (int i = n - 2; i >= 0; i--) {
            if (A[i] < A[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1) {
            reverse(A.begin(), A.end());
            return;
        }

        // find the rightmost element greater than the pivot
        for (int i = n - 1; i > pivot; i--) {
            if (A[i] > A[pivot]) {
                swap(A[i], A[pivot]);
                break;
            }
        }

        // reverse the suffix to get the smallest arrangement
        int i = pivot + 1;
        int j = n - 1;

        while (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    }
};