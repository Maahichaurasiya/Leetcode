// LeetCode 796 - Rotate String
//
// Key Observation:
// A rotation of s will always appear as a substring of s + s.
//
// Example:
// s = "abcde"
// s+s = "abcdeabcde"
// Rotations:
// abcde, bcdea, cdeab, deabc, eabcd
//
// Brute Force:
// 1. Generate every possible rotation of s.
// 2. Compare each rotation with goal.
// Time: O(n^2)
// Space: O(n)
//
// Optimized:
// 1. If lengths are different, return false.
// 2. Create s + s.
// 3. Check whether goal exists inside s + s.
//
// Why s+s?
// Every possible rotation of s appears as a substring of s+s.
//
// Example:
// s = "abcde"
// goal = "cdeab"
// s+s = "abcdeabcde"
//              ^^^^^
//              cdeab -> found
//
// Simple solution:
// return (s + s).find(goal) != string::npos;
//
// Interview-level O(n):
// Use KMP string matching on s+s.
// KMP uses an LPS (Longest Prefix Suffix) array.
//
// Data Structures:
// - string
// - LPS array/vector for KMP
//
// Complexity:
// Simple find: depends on library implementation
// KMP: O(n) time, O(n) space
//
// Main Pattern to Remember:
// "Rotation of string" -> check goal inside s + s
class Solution {
public:
    bool rotateString(string s, string goal) {

        if (s.size() != goal.size()) {
            return false;
        }
        string doublestr = (s + s);
        return doublestr.find(goal) != string::npos;
    }
};