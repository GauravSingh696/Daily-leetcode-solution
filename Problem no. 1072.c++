// 22-11-2024

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int row = matrix.size() , col = matrix[0].size();
        int result = 0;

        for(auto it : matrix) {
            vector<int> vec = it;

            // invert the vector
            for(int i=0;i<vec.size();i++) {
                if(vec[i] == 1)     vec[i] = 0;
                else    vec[i] = 1;
            }

            int count = 0;

            for(auto i : matrix) {
                if(vec == i || i == it) {
                    count++;
                }
            }

            result = max(result , count);
        }

        return result;
    }
};
