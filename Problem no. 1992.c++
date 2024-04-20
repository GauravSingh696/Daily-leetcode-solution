// 20-04-2024

class Solution {
public:
    int bottom_i, bottom_j;

    void dfs(vector<vector<int>> &land, int i, int j)
    {
        if(i==land.size() || j==land[0].size() || land[i][j]==0)
            return;
        
        land[i][j] = 0;

        bottom_i = max(i, bottom_i);
        bottom_j = max(j, bottom_j);

        dfs(land, i+1, j);
        dfs(land, i, j+1);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;
        vector<int> temp;

        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[0].size();j++)
            {
                if(land[i][j]==1)
                {
                    bottom_i = i;
                    bottom_j = j;
                    
                    dfs(land, i, j);

                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(bottom_i);
                    temp.push_back(bottom_j);

                    result.push_back(temp);
                    temp.clear();
                }
            }
        }

        return result;

    }
};
