class NeighborSum {
public:
    int n;
    vector<vector<int>> grid;

    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        this->grid = grid;
    }
    
    int adjacentSum(int value) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == value)
                {
                    int sum = 0;

                    if(i-1 >= 0)
                        sum += grid[i-1][j];
                    if(j-1 >= 0)
                        sum += grid[i][j-1];
                    if(j+1 < n)
                        sum += grid[i][j+1];
                    if(i+1 < n)
                        sum += grid[i+1][j];

                    return sum;
                }
            }
        }
        return 0;
    }
    
    int diagonalSum(int value) {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == value)
                {
                    int sum = 0;

                    if(i-1 >= 0 && j-1 >= 0)
                        sum += grid[i-1][j-1];
                    if(i-1 >= 0 && j+1 < n)
                        sum += grid[i-1][j+1];
                    if(i+1 < n && j-1 >= 0)
                        sum += grid[i+1][j-1];
                    if(i+1 < n && j+1 < n)
                        sum += grid[i+1][j+1];
                        
                    return sum;
                }
            }
        }
        return 0;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */
