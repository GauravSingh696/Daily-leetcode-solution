class Solution {
public:
    long long findScore(vector<int>& nums) {
        vector<pair<int,int>> pr;

        for(int i=0;i<nums.size();i++) {
            pr.push_back({nums[i] , i});
        }

        sort(pr.begin() , pr.end());
        long long result = 0;

        for(int i=0;i<pr.size();i++) {
            int idx = pr[i].second;

            if(nums[idx] != INT_MAX) {
                nums[idx] = INT_MAX;
                result += pr[i].first;

                if(idx+1 < pr.size())
                    nums[idx+1] = INT_MAX;
                if(idx-1 >= 0)
                    nums[idx-1] = INT_MAX;
            }
        }

        return result;
    }
};
