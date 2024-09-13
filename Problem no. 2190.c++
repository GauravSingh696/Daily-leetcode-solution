class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for(int i=0;i<n-1;i++)
        {
            if(nums[i] == key)
            {
                mp[nums[i+1]]++;
            }
        }

        int max_ = 0 , result = 0;

        for(auto it : mp)
        {
            if(max_ < it.second)
            {
                max_ = it.second;
                result = it.first;
            }
        }

        return result;
    }
};
