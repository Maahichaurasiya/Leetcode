class Solution {
public:
    string removeOuterParentheses(string s) {

        string ans = "";

        int balance = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(')
                balance++;
            else
                balance--;

            // One primitive is completed
            if (balance == 0) {

                string primitive = s.substr(start, i - start + 1);

                // Remove outermost '(' and ')'
                string inner = primitive.substr(1, primitive.size() - 2);

                ans += inner;

                start = i + 1;
            }
        }

        return ans;
    }
};