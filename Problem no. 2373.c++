// 12-05-2024

class Solution {
public:
    int solve(vector<vector<int>> &grid, int row, int col)
    {
        int temp = INT_MIN;
        for(int i=row;i<=row+2;i++)
        {
            for(int j=col;j<=col+2;j++)
            {
                temp = max(temp, grid[i][j]);
            }
        }

        return temp;
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> result(n-2, vector<int>(n-2));

        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<n-2;j++)
            {
                result[i][j] = solve(grid, i, j);
            }
        }

        return result;
    }
};
