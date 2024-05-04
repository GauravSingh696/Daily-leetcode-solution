class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x=nums.size();

        return max(nums[0]*nums[1]*nums[x-1],nums[x-1]*nums[x-2]*nums[x-3]);
    }
};
