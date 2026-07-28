/*
Approach:
---------
Traverse each customer's accounts and calculate their total wealth.
Keep track of the maximum wealth found so far.
After checking all customers, return the maximum wealth.

Algorithm:
----------
1. Initialize maxWealth = 0.
2. Traverse each row (customer).
3. Calculate the sum of all accounts in the current row.
4. Update maxWealth if the current wealth is greater.
5. Return maxWealth.

Time Complexity: O(m × n)
Space Complexity: O(1)
*/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for (int i = 0; i < accounts.size(); i++) {
            int wealth = 0;
            for (int j = 0; j < accounts[i].size(); j++) {
                wealth += accounts[i][j];
            }
            maxWealth = max(wealth, maxWealth);
        }
        return maxWealth;
    }
};