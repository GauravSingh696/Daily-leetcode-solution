class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;

        for(auto &it : grid) {
            for(int &i : it) {
                if(i < 0)
                    result++;
            }
        }

        return result;
    }
};
