class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp(n,0);

        for(int i=0 ; i<n ; i++)
        {
            temp[nums[i]-1]=-1;
        }

        vector<int> result;
        for(int i=0 ; i<n ; i++)
        {
            if(temp[i] != -1)
            {
                result.push_back(i+1);
            }
        }

        return result;
    }
};
