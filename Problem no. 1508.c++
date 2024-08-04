// 04-08-2024

class Solution {
public:
    vector<int> subset_sum(vector<int> &nums, int n)
    {
        vector<int> res;

        for(int i=0;i<n;i++)
        {
            vector<int> v;
            int sum = 0;

            for(int j=i;j<n;j++)
            {
                sum += nums[j];
                res.push_back(sum);
            }
        }

        return res;
    }

    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        arr = subset_sum(nums,n);

        sort(arr.begin(), arr.end());

        int result = 0;
        int mod = 1e9+7;

        for(int i=left-1;i<right;i++)
            result = (result + arr[i]) % mod;

        return result;
    }
};
