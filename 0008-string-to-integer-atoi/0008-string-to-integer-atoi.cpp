
// Steps:
// 1. Skip leading spaces
// 2. Check '+' / '-' sign
// 3. Read all consecutive digits
// 4. Build number: num = num * 10 + digit
// 5. Check overflow BEFORE updating num
// 6. Return INT_MAX / INT_MIN if overflow occurs
//
// Overflow check:
// num > INT_MAX / 10 → definitely overflow
// num == INT_MAX / 10 → check last digit
// digit > INT_MAX % 10 → overflow
//
// Example:
// "   -42"       → -42
// "4193 with"    → 4193
// "words 987"    → 0
// "-91283472332" → INT_MIN
//
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int num = 0;
        int i = 0;
        // skip the spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        // check sign
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        // Convert digits
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before adding digit
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > INT_MAX % 10)) {

                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return num * sign;
    }
};