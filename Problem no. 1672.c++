class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int result = 0;

        for(auto it : accounts) {
            result = max(result , accumulate(it.begin(), it.end(), 0));
        }

        return result;
    }
};
