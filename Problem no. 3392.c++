class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int l=0, r=2;
        int cnt = 0;
        while(r<nums.size()) {
            if( (nums[l]+nums[r]) == ((float)nums[l+1]/2) ){
                cnt++;
            }
            l++;
            r++;
        }
        return cnt;
    }
};
