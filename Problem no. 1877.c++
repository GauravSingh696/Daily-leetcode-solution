class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int i=0 , j=n-1;
        int result = 0;

        while(i<j)
        {
            int sum = nums[i++] + nums[j--];
            result = max(result , sum);
        }

        return result;
    }
};
