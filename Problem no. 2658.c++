class Solution {
public:
    int m , n;
    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

    int DFS(vector<vector<int>> &grid, int i, int j) {
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
            return 0;
        
        int fish_count = grid[i][j];
        grid[i][j] = 0;

        for(auto it : dir) {
            int i_ = i + it[0];
            int j_ = j + it[1];

            fish_count += DFS(grid , i_ , j_);
        }

        return fish_count;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int result = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] > 0) {
                    result = max(result , DFS(grid , i , j));
                }
            }
        }

        return result;
    }
};
