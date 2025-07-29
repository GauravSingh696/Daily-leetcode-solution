class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = 0;

        for(int &it : nums) {
            if(it%2 == 0)
                sum += it;
        }
        
        vector<int> result;

        for(auto it : queries) {
            int val = it[0];
            int idx = it[1];
            
            if(nums[idx]%2 == 0)
                sum -= nums[idx];

            int new_val = val + nums[idx];

            if(new_val%2 == 0) {
                sum += new_val;
            }

            nums[idx] = new_val;
            result.push_back(sum);
        }

        return result;
    }
};
