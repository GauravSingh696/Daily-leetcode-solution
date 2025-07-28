class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;

        for(int &it : arr) {
            mp[it]++;
        }

        vector<pair<int, int>> vec;

        for(auto it : mp) {
            vec.push_back({it.second, it.first});
        }

        sort(vec.begin(), vec.end());

        for(int i=0;i<vec.size();i++) {
            int f = vec[i].first;
            int s = vec[i].second;

            k -= f;

            if(k < 0) {
                return vec.size() - i;
            }
        }

        return 0;
    }
};
