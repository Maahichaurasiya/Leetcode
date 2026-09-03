/*

Optimized Approach:

1. Start from the end of the string using index i.
2. Skip all spaces from right to left.
3. If i < 0, stop.
4. Set end = i to mark the end of the current word.
5. Move end left until a space is found.
6. The current word is from end + 1 to i.
7. Add a space to ans if it is not the first word.
8. Add the current word using substr().
9. Set i = end to move towards the previous word.
10. Return ans.

Example:
"  hello   world  "
        ↓
"world"
        ↓
"world hello"

Time Complexity: O(n)
Space Complexity: O(1) extra space
*/
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = s.size() - 1;
        while (i >= 0) {
            while (i >= 0 && s[i] == ' ') {
                i--;
            }
            if (i < 0) {
                break;
            }
            int end = i;
            while (end >= 0 && s[end] != ' ') {
                end--;
            }
            if (!ans.empty()) {
                ans += " ";
            }
            ans += s.substr(end + 1, i - end);
            i = end;
        }
        return ans;
    }
};