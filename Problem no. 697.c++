class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return 1;

        unordered_map<int, int> mp;
        int val = INT_MIN;

        for(auto it : nums)
        {
            mp[it]++;
            val = max(mp[it] , val);
        }

        vector<int> vec;

        for(auto it : mp)
        {
            if(it.second == val)
                vec.push_back(it.first);
        }

        int result = INT_MAX;

        for(auto it : vec)
        {
            int i=0 , j=n-1;
            while(nums[i]!=it)
                i++;

            while(nums[j]!=it)
                j--;
            
            result = min(result , j-i);
        }

        return ++result;
    }
};
