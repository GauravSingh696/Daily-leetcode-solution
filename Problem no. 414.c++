class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> result;

        for(auto it : nums)
        {
            result.insert(it);
            if(result.size()>3)
            {
                result.erase(result.begin());
            }
        }

        return result.size()==3 ? *result.begin() : *result.rbegin();
    }
};
