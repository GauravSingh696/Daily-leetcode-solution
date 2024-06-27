// 28-06-2024

class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        unordered_map<int, int> mp;

        for(int i=0;i<e.size();i++)
        {
            for(int j=0;j<2 ; j++)
            {
                mp[e[i][j]]++;
            }
        }

        pair<int, int> pr(0,0);

        for(auto it : mp)
        {
            if(it.second > pr.second){
                pr.first=it.first;
                pr.second=it.second;
            }
        }
        return pr.first;
    }
};
