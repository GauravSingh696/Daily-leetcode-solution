class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0 , j=0;
        long long result = 0;
        long long sum = 0;
        unordered_set<int> st;

        while(j<n) {
            if(st.find(nums[j]) == st.end()) {
                sum += nums[j];
                st.insert(nums[j]);
            }

            else {
                while(st.find(nums[j]) != st.end()) {
                    sum -= nums[i];
                    st.erase(nums[i++]);
                }
                sum += nums[j];
                st.insert(nums[j]);
            }

            if(j-i+1 == k) {
                result = max(result , sum);
                sum -= nums[i];
                st.erase(nums[i++]);
            }

            j++;
        }

        return result;
    }
};
