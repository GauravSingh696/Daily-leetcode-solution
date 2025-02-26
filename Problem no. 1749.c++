class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int max_subarr_sum = nums[0];
        int sum = nums[0];

        for(int i=1;i<n;i++) {
            sum = max(nums[i] , nums[i]+sum);
            max_subarr_sum = max(sum, max_subarr_sum);
        }

        int min_subarr_sum = nums[0];
        sum = nums[0];

        for(int i=1;i<n;i++) {
            sum = min(nums[i] , nums[i]+sum);
            min_subarr_sum = min(sum, min_subarr_sum);
        }

        return max(abs(min_subarr_sum), max_subarr_sum);
    }
};
