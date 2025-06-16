class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0];
        int result = -1;

        for(int &num : nums) {
            if(num <= min_val)
                min_val = num;
            
            else
                result = max(result, num - min_val);
        }
        
        return result;
    }
};
