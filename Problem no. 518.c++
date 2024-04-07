class Solution {
public:
    int dp[310][10010];
    int solve(int idx, int amount, vector<int> &coins)
    {
        if(amount==0)
            return 1;
        
        if(idx<0)
            return 0;
        
        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        
        int ways=0;
        for(int coin_amount=0 ; coin_amount<=amount ; coin_amount+=coins[idx])
        {
            ways += solve(idx-1, amount-coin_amount, coins);
        }

        return dp[idx][amount]=ways;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(coins.size()-1, amount, coins);
    }
};
