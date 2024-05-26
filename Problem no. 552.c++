// 26-05-2024

class Solution {
public:
    int mod = 1e9+7;
    int dp[100001][2][3];

    int solve(int n , int absent, int late)
    {        
        if(absent >= 2 || late >= 3)
            return 0;

        if(n==0)
            return 1;
        
        if(dp[n][absent][late] != -1)
            return dp[n][absent][late];

        int A = solve(n-1, absent+1, 0) % mod;
        int L = solve(n-1, absent, late+1) % mod;
        int P = solve(n-1, absent, 0) % mod;

        return dp[n][absent][late] = ((A+L) % mod +P) % mod;
    }

    int checkRecord(int n) {
        memset(dp , -1 , sizeof(dp));

        return solve(n, 0, 0);

    }
};
