class Solution {
  private:
    int m, n;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>> &coins, int i, int j, int neu) {
        if(i==m-1 && j==n-1) {
            if(coins[i][j] < 0 && neu > 0) {
                return 0;
            } else {
                return coins[i][j];
            }
        }

        if(i>=m || j>=n) return INT_MIN;
        if(dp[i][j][neu] != INT_MIN) return dp[i][j][neu];


        int take = coins[i][j] + max(solve(coins, i+1, j, neu), solve(coins, i, j+1, neu));

        int skip = INT_MIN;
        if(coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(coins, i+1, j, neu-1);
            int skipRight = solve(coins, i, j+1, neu-1);

            skip = max(skipDown, skipRight);
        }

        return dp[i][j][neu] = max(take, skip);
    }

  public:
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        dp.assign(m+1, vector<vector<int>>(n+1, vector<int>(3, INT_MIN)));

        return solve(coins, 0, 0, 2);
    }
};
