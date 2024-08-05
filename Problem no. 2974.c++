class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++)
        {
            swap(nums[i], nums[i+1]);

            i++;
        }

        return nums;
    }
};
