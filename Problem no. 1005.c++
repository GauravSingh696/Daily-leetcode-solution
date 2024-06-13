class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());

        for(int i=0 ; i<nums.size(); i++)
        {            
            if(nums[i]<0)
            {
                nums[i]=nums[i]*-1;
                k--;
            }
            else if(nums[i]==0)
            {
                k--;
            }
            
            else{
                break;
            }
            if(k<=0)
                break;
        }
        sort(nums.begin(),nums.end());
        if(k%2!=0)
            nums[0]=nums[0]*-1;
        
        return accumulate(nums.begin(),nums.end(),0);
    }
};
