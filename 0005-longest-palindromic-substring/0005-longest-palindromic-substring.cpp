class Solution {
public:
    // Expand from center and find palindrome
    // left & right are the current center
    string expand(string s, int left, int right) {

        // Keep expanding while indexes are valid
        // and both characters are equal
        while (left >= 0 && right < s.size()) {

            // If characters match, expand outward
            if (s[left] == s[right]) {
                left--;
                right++;
            } else {
                // Different characters -> not a palindrome
                break;
            }
        }

        // After loop, left and right are one step outside
        // So actual palindrome starts at left+1
        // Length = right-left-1
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {

        string ans = "";

        // Consider every index as a possible center
        for (int i = 0; i < s.size(); i++) {

            // Odd length palindrome: center = i
            string odd = expand(s, i, i);

            // Even length palindrome: center = i and i+1
            string even = expand(s, i, i + 1);

            // Keep the longest palindrome
            if (odd.size() > ans.size())
                ans = odd;

            if (even.size() > ans.size())
                ans = even;
        }

        return ans;
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Key idea:
// Center → Compare → Expand → Find Longest