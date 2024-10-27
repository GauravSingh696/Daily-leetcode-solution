// 27-10-2024

class Solution {
public:
    int row , col;

    int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &vec) {
        if(i >= row || j >= col)
            return 0;

        if(mat[i][j] == 0)
            return 0;

        if(vec[i][j] != -1)
            return vec[i][j];

        int right = solve(i , j+1 , mat , vec);
        int diagonal = solve(i+1 , j+1 , mat , vec);
        int bottom = solve(i+1 , j , mat , vec);

        return vec[i][j] = 1 + min({right , diagonal , bottom});
    }

    int countSquares(vector<vector<int>>& mat) {
        row = mat.size();
        col = mat[0].size();
        int result = 0;

        vector<vector<int>> vec( row+1 , vector<int> (col+1 , -1));

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(mat[i][j] == 1) {
                    result += solve(i , j , mat , vec);
                }
            }
        }

        return result;
    }
};
