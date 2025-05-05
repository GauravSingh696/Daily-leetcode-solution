class Solution {
public:
    set<vector<int>> st;
    vector<int> vec;

    void solve(int idx, vector<int> &nums) {
        if(idx >= nums.size()) {
            st.insert(vec);
            return ;
        }

        vec.push_back(nums[idx]);
        solve(idx+1, nums);

        vec.pop_back();
        solve(idx+1, nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, nums);

        vector<vector<int>> result;

        for(auto &it : st) {
            result.push_back(it);
        }

        return result;
    }
};
