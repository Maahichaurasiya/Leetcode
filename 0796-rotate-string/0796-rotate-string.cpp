//  Key Observation:
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
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            string rotated = s.substr(i) + s.substr(0, i);
            if (rotated == goal) {
                return true;
            }
        }
        return false;
    }
};