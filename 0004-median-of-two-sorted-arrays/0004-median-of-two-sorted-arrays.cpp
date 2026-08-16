class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> arr;
        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i]);
                i++;
            } else {
                arr.push_back(nums2[j]);
                j++;
            }
        }
         // Remaining elements of nums1
        while (i < n) {
            arr.push_back(nums1[i]);
            i++;
        }

        // Remaining elements of nums2
        while (j < m) {
            arr.push_back(nums2[j]);
            j++;
        }

        int a = arr.size();

        if (a % 2 == 1) {
            return arr[a / 2];
        }
        return (arr[a / 2 - 1] + arr[a / 2]) / 2.0;
    }
};