class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for(int i=0;i<n;i++) {
            if(nums[i] == key)
                vec.push_back({i-k, i+k});
        }

        set<int> st;

        for(auto &it : vec) {
            for(int i=it.first;i<=it.second;i++) {
                if(i >= 0 && i < n) {
                    st.insert(i);
                }
            }
        }

        vector<int> result(st.begin(), st.end());

        return result;
    }
};
