// 14-08-2024

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        int max_ele = *max_element(nums.begin(), nums.end());
        vector<int> vec(max_ele +  1 , 0);

        // all pairs
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int d = abs(nums[i] - nums[j]);
                vec[d]++;
            }
        }

        for(int d=0;d<=max_ele;d++)
        {
            k -= vec[d];
            
            if(k <= 0)
                return d;
        }

        return -1;
    }
};
