class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        
        bool flag1 = true, flag2 = true;
        int n = nums.size();

        for(int i=0;i<n-1;i++)
        {
            if(nums[i] > nums[i+1])
                flag1 = false;
        }

        for(int i=0;i<n-1;i++)
        {
            if(nums[i] < nums[i+1])
                flag2 = false;
        }

        if(flag1 == true)
            return flag1;

        else if(flag2 == true)
            return flag2;
        
        else
            return false;

    }
};
