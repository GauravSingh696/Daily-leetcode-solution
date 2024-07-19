// 19-07-2024

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& mat) {
        vector<int> result;
        for(int i=0 ; i<mat.size() ; i++)
        {
            for(int j=0 ; j<mat[0].size() ; j++)
            {
                bool flag=true;
                for(int k=0 ; k<mat[0].size() ; k++)
                {
                    if(j==k)
                        continue;
                    if(mat[i][j]>mat[i][k])
                    {
                         flag=false;
                         break;
                    }   
                }
                if(!flag)
                    continue;
                
                for(int k=0 ; k<mat.size() ; k++)
                {
                    if(i==k)
                        continue;
                    
                    else if(mat[i][j]<mat[k][j])
                    {
                        flag=false;
                        break;
                    }   
                }

                if(flag)
                    result.push_back(mat[i][j]);
            }
        }
        return result;
    }
};
