class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> mp;

        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        int check = n/2;

        for(auto it : mp)
        {
            if(it.second == check)
                return it.first;
        }

        return 0;
    }
};
