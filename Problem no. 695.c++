class Solution {
public:
    vector<vector<int>> vec = {{0,-1},{-1,0},{0,1},{1,0}};

    void solve(vector<vector<int>>& grid, int &count, int i, int j) {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0) {
            return ;
        }
        
        grid[i][j] = 0;
        count++;

        for(auto &it : vec) {
            int i_ = i + it[0];
            int j_ = j + it[1];

            solve(grid, count, i_, j_);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    int count = 0;
                    solve(grid, count, i, j);
                    result = max(result, count);
                }
            }
        }

        return result;
    }
};
