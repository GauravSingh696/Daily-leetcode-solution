class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=0, j=0;
        int zero = 0, res = 0;

        while(j < n) {
            if(nums[j] == 0)
                zero++;

            while(i <= j && zero > 1) {
                if(nums[i] == 0)
                    zero--;
                
                i++;
            }

            res = max(j-i, res);
            j++;
        }

        return res;
    }
};
