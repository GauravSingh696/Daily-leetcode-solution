// 13-05-2024

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        for(int i=0;i<row;i++)
        {
            if(grid[i][0] == 0)
            {
                for(int j=0;j<col;j++)
                {
                    if(grid[i][j] == 0)
                        grid[i][j] = 1;
                    
                    else
                        grid[i][j] = 0;
                }
            }
        }

        for(int j=1;j<col;j++)
        {
            int zero_cnt = 0;
            int one_cnt = 0;

            for(int i=0;i<row;i++)
            {
                if(grid[i][j] == 0)
                    zero_cnt++;
                
                else
                    one_cnt++;
            }

            if(zero_cnt > one_cnt)
            {
                for(int i=0;i<row;i++)
                {
                    if(grid[i][j] == 0)
                        grid[i][j] = 1;
                
                    else
                        grid[i][j] = 0;
                }
            }
        }

        int result = 0;

        for(int i=0;i<row;i++)
        {
            int k = 0;

            for(int j=col-1;j>=0;j--)
            {
                result += grid[i][j]*pow(2, k++);
            }
        }

        return result;

    }
};
