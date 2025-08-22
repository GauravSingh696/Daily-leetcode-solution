class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        int top = row;
        int bottom = -1;
        int left = col;
        int right = -1;
        
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(grid[i][j] == 1) {
                    top    = min(top, i);
                    bottom = max(bottom , i);
                    left   = min(left, j);
                    right  = max(right, j);
                }
            }
        }
        
        int height = bottom - top + 1;
        int width  = right - left + 1;
        
        return height * width;
    }
};
