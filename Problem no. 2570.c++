class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> mp;

        for(auto it : nums1) {
            if(mp.find(it[0]) != mp.end()) {
                mp[it[0]] += it[1];
            }

            else {
                mp[it[0]] = it[1];
            }
        }

        for(auto it : nums2) {
            if(mp.find(it[0]) != mp.end()) {
                mp[it[0]] += it[1];
            }

            else {
                mp[it[0]] = it[1];
            }
        }

        vector<vector<int>> result;

        for(auto it : mp) {
            result.push_back({it.first , it.second});
        }

        return result;
    }
};
