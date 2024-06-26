// 18-04-2024

class Solution {
public:
    int count = 0;

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if(i<0 || grid.size()<=i || j<0 || grid[i].size()<=j || grid[i][j]==0)
        {
            count++;
            return;
        }

        if(grid[i][j]==-1)
            return;
        
        grid[i][j]=-1;

        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(grid, i, j);
                    break;
                }
            }
        }

        return count;
    }
};
