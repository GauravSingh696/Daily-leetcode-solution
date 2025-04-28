class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();

        int i=0, j=0;
        long long sum = 0 , result = 0;

        while(j<n) {
            sum += nums[j];

            while(sum*(j-i+1) >= k) {
                sum -= nums[i];
                i++;
            }
            
            result += j-i+1;
            j++;
        }

        return result;
    }
};
