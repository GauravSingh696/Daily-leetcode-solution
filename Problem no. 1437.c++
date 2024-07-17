class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> vec;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
                vec.push_back(i);
        }

        if(vec.empty())
            return true;

        for(int i=0;i<vec.size()-1;i++)
        {
            int diff = (vec[i+1] - vec[i])-1;
            
            if(diff < 0)
                diff = 0;

            if(diff < k)
                return false;
        }

        return true;
    }
};
