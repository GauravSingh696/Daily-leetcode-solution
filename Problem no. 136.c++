class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for(auto i : nums)
        {
            freq[i]++;
        }

        for(auto i:freq)
        {
            if(i.second==1)
                return i.first;
        }

        return -1;
    }
};
