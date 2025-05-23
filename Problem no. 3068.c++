class Solution {
public:
    typedef long long LL;

    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> profit;
        LL sum = 0;

        for(int i=0;i<nums.size();i++) {
            sum += nums[i];

            profit.push_back((nums[i] ^ k) - nums[i]);
        }

        sort(profit.begin(), profit.end(), greater<int>());
        
        for(int i=0;i<profit.size()-1;i+=2) {
            LL val = profit[i] + profit[i+1];

            if(val > 0)
                sum += val;
        }

        return sum;
    }
};
