class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        queue<int> que;
        if(mat.size()*mat[0].size()!=r*c)
            return mat;
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                que.push(mat[i][j]);
            }
        }

        vector<vector<int>> result;
        for(int i=0;i<r;i++)
        {
            vector<int> temp;
            for(int j=0;j<c;j++)
            {
                if(!que.empty())
                {
                    temp.push_back(que.front());
                    que.pop();
                }
            }

            result.push_back(temp);
        }

        return result;
    }
};
