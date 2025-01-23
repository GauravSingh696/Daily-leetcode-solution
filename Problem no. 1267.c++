class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<int> server_row(row);
        vector<int> server_col(col);

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 1) {
                    server_row[i]++;
                    server_col[j]++;
                }
            }
        }

        int result = 0;

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 1) {
                    if(server_row[i] > 1 || server_col[j] > 1) {
                        result++;
                    }
                }
            }
        }

        return result;
    }
};
