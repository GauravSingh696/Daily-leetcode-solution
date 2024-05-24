class Solution {
public:
    int n, m;
    int result;
    int non_obstacles;

    vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};

    void solve(vector<vector<int>>& grid, int count, int i, int j)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==-1)
            return ;
        
        if(grid[i][j] == 2)
        {
            if(count == non_obstacles)
            {
                result++;
            }

            return ;
        }

        grid[i][j] = -1;

        for(auto it : dir)
        {
            int i_ = i + it[0];
            int j_ = j + it[1];

            solve(grid, count+1, i_ , j_);
        }

        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int start_x , start_y;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 0)
                    non_obstacles++;
                
                if(grid[i][j] == 1)
                {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        non_obstacles += 1;

        int count = 0;

        solve(grid, count, start_x, start_y);

        return result;
    }
};
