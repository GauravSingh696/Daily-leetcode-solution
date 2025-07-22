class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int, int> mp;
        int i = 0, n = nums.size();
        int sum = 0, result = INT_MIN;

        for(int j=0;j<n;j++) {
            sum += nums[j];
            mp[nums[j]]++;

            while(i<n && mp[nums[j]] > 1) {
                sum -= nums[i];
                mp[nums[i]]--;

                if(mp[nums[j]] == 0)
                    mp.erase(nums[j]);

                i++;
            }

            result = max(result, sum);
        }

        return result;
    }
};
