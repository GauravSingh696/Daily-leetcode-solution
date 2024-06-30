class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        set<int> st;

        for(auto i:arr)
        {
            st.insert(i);
        }

        int idx=1;
        unordered_map<int,int> mp;

        for(auto it : st)
        {
            mp[it]=idx++;
        }

        vector<int> result;

        for(auto it:arr)
        {
            result.push_back(mp[it]);
        }
        
        return result;
    }
};
