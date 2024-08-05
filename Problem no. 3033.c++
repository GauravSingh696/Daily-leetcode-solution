class Solution {
public:
    int solve(vector<vector<int>> &matrix , int j)
    {
        vector<int> vec;

        for(int i=0;i<matrix.size();i++)
        {
            vec.push_back(matrix[i][j]);
        }

        return *max_element(vec.begin(), vec.end());
    }

    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j] == -1)
                    matrix[i][j] = solve(matrix, j);
            }
        }

        return matrix;
    }
};
