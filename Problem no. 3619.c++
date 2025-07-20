class Solution {
public:
    int row, col;
    vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    
    long int solve(int i, int j, vector<vector<int>>& grid) {
        if(i<0 || j<0 || i>=row || j>=col || grid[i][j] == 0)
            return 0;

        long int val = grid[i][j];
        grid[i][j] = 0;

        for(auto it : dir) {
            int i_ = i + it[0];
            int j_ = j + it[1];
            
            val += solve(i_, j_, grid);
        }
        
        return val;
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        row = grid.size();
        col = grid[0].size();

        int result = 0;

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] > 0) {
                    long int val = solve(i, j, grid);
                    
                    if(val % k == 0)
                        result++;
                }
            }
        }

        return result;
    }
};
