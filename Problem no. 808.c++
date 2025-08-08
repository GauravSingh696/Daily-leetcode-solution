class Solution {
public:
    vector<vector<double>> serve = {{100, 0},{75, 25},{50, 50},{25, 75}};
    vector<vector<double>> dp;

    double solve(int A, int B) {
        if(A <= 0 && B <= 0)
            return 0.5;
        
        if(A <= 0)
            return 1.0;
        
        if(B <= 0)
            return 0.0;
        
        if(dp[A][B] != -1.0)
            return dp[A][B];
        
        double prob = 0.0;

        for(auto it : serve) {
            int A_serve = it[0];
            int B_serve = it[1];

            prob += solve(A - A_serve , B - B_serve);
        }

        return dp[A][B] = 0.25 * prob;
    }

    double soupServings(int n) {
        if(n >= 5000)
            return 1;

        dp.resize(n+1, vector<double>(n+1, -1.0));

        return solve(n, n);
    }
};
