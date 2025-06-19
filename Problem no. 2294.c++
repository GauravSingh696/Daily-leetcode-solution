class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int min_val = nums[0];
        int result = 1;

        for(int i=0;i<nums.size();i++) {
            if(nums[i] - min_val > k) {
                result++;
                min_val = nums[i];
            }
        }

        return result;
    }
};
