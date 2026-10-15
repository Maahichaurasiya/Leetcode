class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;

        //  Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = -1;
            } else {
                left[i] = st.top();
            }

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        //  Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n;
            } else {
                right[i] = st.top();
            }

            st.push(i);
        }

        // Calculate contribution
        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long leftCount = i - left[i];
            long long rightCount = right[i] - i;

            long long contribution = (long long)arr[i] * leftCount * rightCount;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};