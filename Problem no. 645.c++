class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        vector<int> arr(n+1,0);

        for(int i=0;i<n;i++)
        {
            arr[nums[i]]++;
        }

        for(int i=0;i<=n;i++)
        {
            if(arr[i]>1)
            {
                result.push_back(i);
            }
        }

        for(int i=1;i<=n;i++)
        {
            int j;
            for(j=0;j<n;j++)
            {
                if(nums[j]==i)
                    break;
            }

            if(j==n)
                result.push_back(i);
        }

        return result;
    }
};
