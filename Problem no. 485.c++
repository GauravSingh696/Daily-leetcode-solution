class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int count=0, result=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count = 0;
            }

            else
            {
                count++;
                result = max(result, count);
            }
        }

        return result;
    }
};
