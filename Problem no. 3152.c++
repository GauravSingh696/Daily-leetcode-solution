class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> vec(n,0);

        for(int i=1;i<n;i++) {
            if(nums[i]%2 == nums[i-1]%2) {
                vec[i] = vec[i-1]+1 ;
            }
            else {
                vec[i] = vec[i-1];
            }
            cout<<vec[i]<<" ";
        }

        vector<bool> result;

        for(auto it : queries) {
            if((vec[it[1]]-vec[it[0]]) > 0)
                result.push_back(false);
            else    
                result.push_back(true);
        }

        return result;
    }
};
