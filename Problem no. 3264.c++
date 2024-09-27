class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--) {
            int val = *min_element(nums.begin(), nums.end());

            for(int i=0;i<nums.size();i++) {
                if(val == nums[i]) {
                    nums[i] = nums[i]*multiplier;
                    break;
                }
            }
        }

        return nums;
    }
};
