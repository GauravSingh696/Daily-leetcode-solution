class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0 , j=n-1;

        while(i<=j)
        {
            if(nums[i] != target)
                i++;
            else
                return i;
            
            if(nums[j] != target)
                j--;
            else
                return j;
        }

        return -1;
    }
};
