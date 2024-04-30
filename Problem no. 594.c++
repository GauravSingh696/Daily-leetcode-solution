class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        int result = 0;

        for(int val : nums)
        {
            mp[val]++;
        }

        for(auto i : mp)
        {
            if(mp.find(i.first-1) != mp.end())
            {
                result = max(result, i.second + mp[i.first-1]);
            }
        }

        return result;
    }
};
