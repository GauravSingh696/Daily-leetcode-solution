class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i=0 , j=n-1;

        bool flag1 = true , flag2 = true;
        vector<int> result(2, -1);

        while(i<=j)
        {
            if(flag1 && nums[i] != target)
                i++;
            else
            {
                flag1 = false;
                result[0] = i;
            }
            
            if(flag2 && nums[j] != target)
                j--;
            else
            {
                flag2 = false;
                result[1] = j;
            }

            if(!flag1 && !flag2)
                break;
        }

        return result;
    }
};
