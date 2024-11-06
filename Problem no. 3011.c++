class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            int idx=-1;
            
            for(int j=i+1;j<nums.size();j++) {
                if(nums[j]<nums[i]) {
                    if(__builtin_popcount(nums[i]) == __builtin_popcount(nums[j]))
                        swap(nums[i],nums[j]);
                    else
                        return false;
                }
            }
        }
        return true;
    }
};
