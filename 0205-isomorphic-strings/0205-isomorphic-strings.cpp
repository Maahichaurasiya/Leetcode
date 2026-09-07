// Optimization:
// Instead of unordered_map, use fixed-size arrays of 256 characters.
//
// Time: O(n)
// Space: O(1)
//
// Two arrays are used to maintain both s -> t and t -> s mapping.
// i + 1 is stored because 0 represents "no mapping yet".

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp1[256] = {0};
        int mp2[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (mp1[s[i]] != mp2[t[i]]) {
                return false;
            }
            mp1[s[i]] = i + 1;
            mp2[t[i]] = i + 1;
        }
        return true;
    }
};