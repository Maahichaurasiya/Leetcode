// Longest Common Prefix
//
// Approach:
// 1. Sort all strings lexicographically.
// 2. Compare the first and last strings.
// 3. Their common prefix is the common prefix of all strings.
// 4. Compare characters until they differ.
// 5. Return the matched prefix.
//
// Example:
// ["flower", "flow", "flight"]
// Sorted -> ["flight", "flow", "flower"]
// Compare "flight" & "flower" -> "fl"
//
// Time: O(n log n * m)
// Space: O(1) auxiliary
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size() - 1];
        int minLength = min(s1.size(), s2.size());
        string ans = "";
        if (strs.empty()) {
            return "";
        }
        for (int i = 0; i < minLength; i++) {
            if (s1[i] != s2[i]) {
                break;
            }
            ans += s1[i];
        }
        return ans;
    }
};