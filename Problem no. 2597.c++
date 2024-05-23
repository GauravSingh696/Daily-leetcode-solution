// 23-05-2024

class Solution {
public:
    int result;
    int K;

    void solve(vector<int> &nums, int idx, unordered_map<int, int> &mp)
    {
        if(idx >= nums.size())
        {
            result++;
            return;
        }

        solve(nums, idx+1, mp);

        if(!mp[nums[idx] - K] && !mp[nums[idx] + K])
        {
            mp[nums[idx]]++;
            solve(nums, idx+1, mp);
            mp[nums[idx]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        result = 0;
        K = k;

        unordered_map<int , int> mp;

        solve(nums, 0, mp);

        return result-1;
    }
};
