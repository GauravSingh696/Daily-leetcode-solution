// 01-09-2024

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& org, int m, int n) {
        int size = org.size();

        if(n*m != size)
            return {};
        
        vector<vector<int>> result;
        int k=0;
        
        for(int i=0;i<m;i++)
        {
            vector<int> temp;

            for(int j=0;j<n;j++)
            {
                temp.push_back(org[k++]);
            }
            
            result.push_back(temp);
        }

        return result;
    }
};
