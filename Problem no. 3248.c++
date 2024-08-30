class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int row = 0;
        int col = 0;

        for(auto it : commands)
        {
            if(row > 0 && it == "UP")
            {
                row--;
            }
            else if(row < n-1 && it == "DOWN")
            {
                row++;
            }
            else if(col > 0 && it == "LEFT")
            {
                col--;
            }
            else if(col < n-1 && it == "RIGHT")
            {
                col++;
            }
        }

        return (row*n) + col;
    }
};
