class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        
        for(int &it : nums) {
            mp[it]++;
        }

        int result = 0;

        for(auto &it : mp) {
            if(mp.find(it.first-1) != mp.end()) {
                result = max(result, mp[it.first] + mp[it.first-1]);
            }
        }

        return result;
    }
};
