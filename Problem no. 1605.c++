// 20-07-2024

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int row = rowSum.size();
        int col = colSum.size();

        vector<vector<int>> result(row, vector<int>(col, 0));

        int i=0;
        int j=0;

        while(i<row && j<col)
        {
            result[i][j] = min(rowSum[i] , colSum[j]);

            rowSum[i] -= result[i][j];
            colSum[j] -= result[i][j];

            if(rowSum[i]==0)
                i++;
            
            else if(colSum[j]==0)
                j++;
        }

        return result;
        
    }
};
