class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";
        int level = 0;

        // Traverse every character
        for (char ch : s) {

            if (ch == '(') {

                // If level > 0, this '(' is not outermost
                if (level > 0) {
                    ans.push_back(ch);
                }

                // Increase nesting level
                level++;

            } else {

                // Decrease level before checking ')'
                level--;

                // If level > 0, this ')' is not outermost
                if (level > 0) {
                    ans.push_back(ch);
                }
            }
        }

        // Return string after removing outermost parentheses
        return ans;
    }
};

/*
Approach:
- Maintain 'level' to track current parenthesis depth.
- Skip '(' when level == 0 → outermost opening bracket.
- Decrease level for ')'.
- Skip ')' when level becomes 0 → outermost closing bracket.
- Add all inner parentheses to 'ans'.

Time Complexity: O(n)
Space Complexity: O(n) for the answer
*/