class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount+1,-2);
        return helper(coins, amount, memo);
    }
private:
    int helper(vector<int>& coins, int amount, vector<int>& memo) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;
        if(memo[amount] != -2) return memo[amount];
        
        int min_count = INT_MAX;
        
        for (int i=0;i<coins.size();i++) {
            int res = helper(coins, amount - coins[i],memo);

            if (res >= 0 && res < min_count) {
                min_count = 1 + res;
            }
        }
        
        memo[amount] = (min_count == INT_MAX) ? -1 : min_count;
        return memo[amount];
    }
};