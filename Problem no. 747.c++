class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_e = nums[0];
        int n = nums.size();
        int index = 0;

        for(int i=0;i<n;i++)
        {
            if(max_e < nums[i])
            {
                index = i;
                max_e = nums[i];
            }
        }

        sort(nums.begin(), nums.end());

        int second = nums[n-2];

        if(second*2 <= max_e)
            return index;
        
        else 
            return -1;
    }
};
