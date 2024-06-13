class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%3!=0)
            return false;
        int x=sum/3;
        int csum=0,count=0;
        for(int i=0 ; i<nums.size()-1 ; i++)
        {
            csum+=nums[i];
            if(csum==x)
            {
                csum=0;
                count++;
                if(count>=2)
                    return true;
            }
        }
            
        return false;
    }
};
