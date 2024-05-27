// 27-05-2024

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();

        for(int i=0 ; i<=n ; i++)
        {   
            int temp=0;
            for(int j=0 ; j<n ; j++)
            {
                if(nums[j]>=i){
                    temp++;
                }
            }
            if(temp==i)
                return temp;
        }

        return -1;
    }
};
