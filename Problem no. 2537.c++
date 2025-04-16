class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0 , j=0;
        unordered_map<int, int> mp;
        long long pair = 0;
        long long result = 0;

        while(j<n) {
            pair += mp[nums[j]];
            mp[nums[j]]++;

            while(pair >= k) {
                result += n-j;
                mp[nums[i]]--;
                pair -= mp[nums[i]];
                i++;
            }

            j++;
        }

        return result;
    }
};
