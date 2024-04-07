class Solution {
public:
    int dp[10010];
    int solve(int amount, vector<int> &coins)
    {
        if(amount == 0)
            return 0;
        
        if(dp[amount] != -1)
            return dp[amount];
        
        int result = INT_MAX;
        for(auto coin : coins)
        {
            if(amount-coin >= 0)
                result = min(result+0LL, solve(amount-coin, coins) + 1LL);
        }

        return dp[amount] = result;
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        int result = solve(amount, coins);
        return result == INT_MAX ? -1 : result;
    }
};
