
// Optimized Approach: Frequency Counting
//
// Idea:
// Anagrams contain the same characters with the same frequency.
// Order of characters does not matter.
//
// Example:
// s = "anagram"
// t = "nagaram"
// Both have:
// a -> 3, n -> 1, g -> 1, r -> 1, m -> 1
//
// Steps:
// 1. If lengths are different -> return false.
// 2. Create a frequency array of size 26.
// 3. For every character in s, increment its frequency.
// 4. For every character in t, decrement its frequency.
// 5. If every frequency becomes 0 -> anagram.
// 6. Otherwise -> not an anagram.
//
// Why freq[26]?
// Only lowercase English letters (a-z) are considered.
//
// ch - 'a' maps:
// 'a' -> 0, 'b' -> 1, ..., 'z' -> 25
//
// Time Complexity: O(n)
// Space Complexity: O(1) because array size is fixed (26).
//
// Pattern:
// Anagram -> Frequency Counting

class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        if (s.size() != t.size()) {
            return false;
        }
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        for (char ch : t) {
            freq[ch - 'a']--;
        }
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
};