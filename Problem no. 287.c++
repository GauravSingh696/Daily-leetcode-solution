//  24-03-2024

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> num(n);

        for(int i=0;i<n;i++)
        {
            num[i]=0;
        }
        
        for(int i=0;i<n;i++)
        {
            num[nums[i]]++;
            if(num[nums[i]]>1)
                return nums[i];
        }

        return -1;
    }
};
