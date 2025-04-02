class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();

        long long result = INT_MIN;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=j+1;k<n;k++) {
                    long long val = (long long)(nums[i] - nums[j]) * (long long)nums[k];
                    result = max(result , val);
                }
            }
        }

        return result < 0 ? 0 : result;
    }
};
