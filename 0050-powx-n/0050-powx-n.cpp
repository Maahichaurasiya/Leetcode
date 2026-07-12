// Binary Exponentiation (Fast Power)
//
// Idea:
// - Convert negative exponent: x^-n = (1/x)^n
// - Process exponent bit by bit.
// - If current bit is 1, multiply answer by current base.
// - Square the base after every step.
// - Divide exponent by 2 (right shift concept).
//
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long binForm = n;
        if (n < 0) {
            x = 1 / x;
            binForm = -binForm;
        }
        double ans = 1;

        while (binForm > 0) {
            if (binForm % 2 == 1) {
                ans = ans * x;
            }
            x *= x;
            binForm /= 2;
        }
        return ans;
    }
};