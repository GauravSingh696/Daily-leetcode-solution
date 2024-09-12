class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;

        for(int i=0;i<paths.size();i++)
        {
            mp[paths[i][1]]++;
            mp[paths[i][0]]++;
        }

        vector<string> vec;

        for(auto it : mp)
        {
            if(it.second == 1)
                vec.push_back(it.first);
        }

        for(int i=0;i<paths.size();i++)
        {
            if((mp[paths[i][1]] == 1) && mp.find(paths[i][1]) != mp.end())
                return paths[i][1];
        }
            
        return "";
    }
};
