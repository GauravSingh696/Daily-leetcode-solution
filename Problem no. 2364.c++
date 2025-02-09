class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n;i++) {
            nums[i] = nums[i] - i;
        }

        unordered_map<int, int> mp;
        mp[nums[0]]++;
        long long result = 0;

        for(int j=1;j<n;j++) {
            int count_j = mp[nums[j]];

            result += j - count_j;

            mp[nums[j]]++;
        }

        return result;
    }
};
