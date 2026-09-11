class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        // starting point
        for (int i = 0; i < s.size(); i++) {
            // ending point
            int freq[26] = {0};
            for (int j = i; j < s.size(); j++) {
                // counting frequency
                freq[s[j] - 'a']++;

                    // finding maximum and minimum
                    int maxi = 0;
                int mini = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxi = max(maxi, freq[k]);
                        mini = min(mini, freq[k]);
                    }
                }
                // adding beauty to ans
                ans += maxi - mini;
            }
        }
        return ans;
    }
};

// TC=> O(n²)
// SC=>O(1)