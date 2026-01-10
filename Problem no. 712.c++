class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, string &s1, string &s2) {
        if(i >= m && j >= n) {
            return 0;
        } else if(i >= m) {
            return s2[j] + solve(i, j+1, s1, s2);
        } else if(j >= n) {
            return s1[i] + solve(i+1, j, s1, s2);
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s1[i] == s2[j]) {
            return solve(i+1, j+1, s1, s2);
        }

        int remove_s1 = s1[i] + solve(i+1, j, s1, s2);
        int remove_s2 = s2[j] + solve(i, j+1, s1, s2);

        return dp[i][j] = min(remove_s1, remove_s2);
    }

    int minimumDeleteSum(string s1, string s2) {
        m = s1.size();
        n = s2.size();
        dp.assign(m+1, vector<int> (n+1, -1));

        return solve(0, 0, s1, s2);
    }
};
