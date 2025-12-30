class Solution {
    bool solve(vector<vector<int>>& grid, int a, int b) {
        vector<int> nums;

        for (int i = a; i < a + 3; i++) {
            for (int j = b; j < b + 3; j++) {
                nums.push_back(grid[i][j]);
            }
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < 9; i++) {
            if (nums[i] != i + 1)
                return false;
        }

        int sum = grid[a][b] + grid[a][b + 1] + grid[a][b + 2];

        // check rows
        for (int i = a; i < a + 3; i++) {
            if (grid[i][b] + grid[i][b + 1] + grid[i][b + 2] != sum)
                return false;
        }

        // check columns
        for (int j = b; j < b + 3; j++) {
            if (grid[a][j] + grid[a + 1][j] + grid[a + 2][j] != sum)
                return false;
        }

        if (grid[a][b] + grid[a + 1][b + 1] + grid[a + 2][b + 2] != sum)
            return false;

        if (grid[a][b + 2] + grid[a + 1][b + 1] + grid[a + 2][b] != sum)
            return false;

        return true;
    }

  public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int result = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i <= row - 3; i++) {
            for (int j = 0; j <= col - 3; j++) {
                if (solve(grid, i, j))
                    result++;
            }
        }

        return result;
    }
};
