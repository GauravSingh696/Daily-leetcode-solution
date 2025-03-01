class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for(int i=0;i<n-1;i++) {
            if(nums[i] == nums[i+1]) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }

        int cnt = count(nums.begin(), nums.end(), 0);
        vector<int> result;

        for(int i=0;i<nums.size();i++) {
            if(nums[i] != 0)
                result.push_back(nums[i]);
        }

        for(int i=0;i<cnt;i++) {
            result.push_back(0);
        }

        return result;
    }
};
