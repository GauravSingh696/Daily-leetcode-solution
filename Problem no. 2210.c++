class Solution {
public:
    int countHillValley(vector<int>& nums) {
        for(int i=1;i<nums.size();i++) {
            if(nums[i] == nums[i-1]) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        int result = 0;

        for(int i=1;i<nums.size()-1;i++) {
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
                result++;
            
            else if(nums[i] < nums[i-1] && nums[i] < nums[i+1])
                result++;
        }

        return result;
    }
};
