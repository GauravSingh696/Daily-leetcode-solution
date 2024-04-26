// 26-04-2024

class Solution {
public:
    int n;
    int arr[201][201];

    int solve(int row, int col, vector<vector<int>> &grid)
    {
        if(row == n-1)
            return grid[row][col];
        
        if(arr[row][col] != -1)
            return arr[row][col];
        
        int ans = INT_MAX;

        for(int nextcol=0 ; nextcol<n ; nextcol++)
        {
            if(nextcol != col)
            {
                ans = min(ans, solve(row+1, nextcol, grid));
            }
        }

        return arr[row][col] = grid[row][col] + ans;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size(); // row=n, col=n
        memset(arr, -1, sizeof(arr));

        int result = INT_MAX;

        for(int col=0;col<n;col++)
        {
            result = min(result, solve(0, col, grid));
        }

        return result;
    }
};
