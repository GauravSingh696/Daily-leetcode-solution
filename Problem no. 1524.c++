class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd_count = 0 , pre_sum = 0;
        int mod = 1e9+7;

        for(int a : arr) {
            pre_sum += a;
            odd_count += pre_sum % 2;
        }
        odd_count += (arr.size() - odd_count) * odd_count;
        return odd_count % mod;
    }
};
