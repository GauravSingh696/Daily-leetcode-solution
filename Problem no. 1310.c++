// 13-09-2024

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int> result;
        
        for(int i=0;i<q.size();i++)
        {
            int Xor = 0;

            for(int j=q[i][0];j<=q[i][1];j++)
            {
                Xor ^= arr[j];
            }

            result.push_back(Xor);
        }

        return  result;
    }
};
