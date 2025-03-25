class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = INT_MAX;
        int i=0 , j=k-1;

        while(j<n) {
            result = min(result , abs(nums[i++] - nums[j++]));
        }

        return result ;
    }
};
