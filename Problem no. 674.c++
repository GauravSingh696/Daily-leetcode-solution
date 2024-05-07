class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MIN;

        for(int i=0;i<n;i++)
        {
            int count=1;
            for(int j=i;j<n-1;j++)
            {
                if(nums[j]<nums[j+1])
                {
                    count++;
                }
                else
                {
                    break;
                }
            }

            result = max(result, count);
        }

        return result;
    }
};
