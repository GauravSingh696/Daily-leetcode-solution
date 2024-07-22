// 22-07-2024

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;

        for(int i=0;i<names.size();i++)
        {
            mp[heights[i]] = names[i];
        }

        vector<string> result;

        for(auto it : mp)
        {
            result.push_back(it.second);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
