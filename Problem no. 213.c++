class Solution {
public:
    int solve(int i, bool flag, vector<int> &nums, vector<int> &dp) {
        if(i>=nums.size() || (i==nums.size()-1 && flag))
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int take     = nums[i] + solve(i+2, flag, nums, dp);
        int not_take = solve(i+1, flag, nums, dp);

        return dp[i] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        if(nums.size() < 2)
            return nums[0];
        
        vector<int> dp(nums.size()+1, -1);

        int a = solve(1, false, nums, dp);

        dp.clear();
        dp.resize(nums.size()+1, -1);

        int b = solve(0, true, nums, dp);

        return max(a, b);
    }
};
