class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int zero = 0 , result = 0;

        while(j<n) {
            if(nums[j] == 0)
                zero++;

            while(zero > k) {
                if(nums[i] == 0)
                    zero--;
                
                i++;
            }

            result = max(result, j-i+1);
            j++;
        }

        return result;
    }
};
