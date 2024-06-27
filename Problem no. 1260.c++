class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        queue<int> que;

        int row = grid.size();
        int col = grid[0].size();

        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                que.push(grid[i][j]);
            }
        }

        while(k--)
        {
            int temp = que.front();
            que.push(temp);
            que.pop();
        }

        for(int i=row-1;i>=0;i--)
        {
            for(int j=col-1;j>=0;j--)
            {
                grid[i][j] = que.front();
                que.pop();
            }
        }

        return grid;
    }
};
