class Solution {
public:
    bool CheckPrime(int val) {
        if(val <= 1)
            return false;
        if(val == 2 || val == 3)
            return true;

        if(val%2 == 0 || val%3 == 0)
            return false;

        for(int i=5;i*i<=val;i+=6) {
            if(val%i == 0 || val%(i+2) == 0)
                return false;
        }

        return true;
    }
    
    long long splitArray(vector<int>& nums) {
        long long sum_A = 0, sum_B = 0;
        int n = nums.size();

        for(int i=0;i<n;i++) {
            if(CheckPrime(i))
                sum_A += nums[i];

            else
                sum_B += nums[i];
        }

        return abs(sum_A - sum_B);
    }
};©leetcode
