
// Idea:
// Two strings are anagrams if they contain the same characters
// with the same frequency.
//
// Approach:
// 1. If lengths are different -> not anagrams.
// 2. Sort both strings.
// 3. Compare the sorted strings.
// 4. If all characters match -> true.
//
// Example:
// s = "listen"
// t = "silent"
//
// After sorting:
// s = "eilnst"
// t = "eilnst"
//
// Time Complexity: O(n log n)
// Space Complexity: O(n) approximately
//
// Pattern:
// Anagram -> Sort + Compare

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
};