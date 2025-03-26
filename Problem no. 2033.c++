class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> vec;

        for(auto &i : grid) {
            for(auto &j : i) {
                vec.push_back(j);
            }
        }

        sort(vec.begin(), vec.end());

        int len = vec.size();
        int tar = vec[len/2];
        int result = 0;

        for(auto &it : vec) {
            if(it%x != tar%x)
                return -1;
            
            result += abs(tar - it) / x;
        }

        return result;
    }
};
