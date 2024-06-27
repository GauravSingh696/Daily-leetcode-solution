class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        int vec[m][n]={0};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                vec[i][j] = 0;
            }
        }

        for(int i=0;i<indices.size();i++)
        {
            for(int b=0;b<n;b++)
            {
                vec[indices[i][0]][b]++;
            }

            for(int a=0;a<m;a++)
            {
                vec[a][indices[i][1]]++;
            }
        }

        int result = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vec[i][j]%2 != 0)
                    result++;
            }
        }

        return result;
    }
};
