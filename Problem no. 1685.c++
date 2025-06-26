class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_sum(nums);

        for(int i=1;i<n;i++) {
            pre_sum[i] += pre_sum[i-1];
        }

        vector<int> result(n);

        for(int i=0;i<n;i++) {
            int right_sum = 0;
            int other_sum = 0;

            if(i < n-1) {
                right_sum  = pre_sum[n-1] - pre_sum[i];
                other_sum = (n-i-1) * nums[i];
            }

            int val1 = right_sum - other_sum;

            int left_sum = 0;
            other_sum    = 0;

            if(i > 0) {
                left_sum  = pre_sum[i-1];
                other_sum = (i) * nums[i];
            }

            int val2 = other_sum - left_sum;

            result[i] = (val1 + val2);
        }

        return result;
    }
};
