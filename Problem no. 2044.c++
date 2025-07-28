class Solution {
public:
    int solve(int idx, int curr, vector<int>& nums, int maxOr, vector<vector<int>>& dp) {
        if(idx == nums.size())
            return maxOr == curr ? 1 : 0 ;
        
        if(dp[idx][curr] != -1)
            return dp[idx][curr];
        
        int take     = solve(idx+1, nums[idx] | curr , nums, maxOr, dp);
        int not_take = solve(idx+1, curr, nums, maxOr, dp);

        return dp[idx][curr] = take + not_take;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;

        for(int &it : nums) {
            maxOr |= it;
        }

        vector<vector<int>> dp(nums.size()+1, vector<int>(maxOr+1, -1));

        return solve(0, 0, nums, maxOr, dp);
    }
};
