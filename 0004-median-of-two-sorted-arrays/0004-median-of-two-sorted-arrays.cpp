class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> arr;
        for (int i = 0; i < n; i++) {
            arr.push_back(nums1[i]);
        }
        for (int i = 0; i < m; i++) {
            arr.push_back(nums2[i]);
        }
        sort(arr.begin(), arr.end());

        int a = arr.size();

        if (a % 2 == 1) {
            return arr[a / 2];
        }
        return (arr[a / 2 - 1] + arr[a / 2]) / 2.0;
    }
};