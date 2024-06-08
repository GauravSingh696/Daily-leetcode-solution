class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        queue<int> even;
        queue<int> odd;

        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2 == 0)
                even.push(nums[i]);
            else
                odd.push(nums[i]);
        }

        vector<int> result;

        for(int i=0;i<n;i++)
        {
            if(i%2 == 0)
            {
                result.push_back(even.front());
                even.pop();
            }

            else
            {
                result.push_back(odd.front());
                odd.pop();
            }
        }

        return result;
        
    }
};
