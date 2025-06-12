class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int result = 0;

        for (int i = 0 ; i < nums.size() - 1 ; i++)
            result = max(result , abs(nums[i + 1] - nums[i]));

        result = max(result , abs(nums[nums.size() - 1] - nums[0]));

        return result;
    }
};
