class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>> dp;

    int solve(int n, int val, int x) {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;

        int curr = pow(val, x);

        if(curr > n)
            return 0;
        
        if(dp[n][val] != -1)
            return dp[n][val];
        
        int take     = solve(n - curr, val+1, x);
        int not_take = solve(n, val+1, x);

        return dp[n][val] = (take + not_take) % mod;
    }

    int numberOfWays(int n, int x) {
        dp.resize(n+1, vector<int>(n+1, -1));

        return solve(n, 1, x);
    }
};
