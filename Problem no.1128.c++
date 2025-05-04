class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<int, int> mp;
        int result = 0;

        for(auto &it : dominoes) {
            if(it[0] > it[1])
                swap(it[0] , it[1]);

            int u = it[0] * 10;
            int v = it[1];

            int val = u + v;
            
            result += mp[val];

            mp[val]++;
        }

        return result;
    }
};
