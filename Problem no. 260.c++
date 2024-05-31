// 31-05-2024

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        vector<int> result;

        for(auto &it : mp)
        {
            if(it.second == 1)
                result.push_back(it.first);
        }

        return result;
    }
};
