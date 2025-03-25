class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n = inter.size();
        vector<vector<int>> result;
        sort(inter.begin() , inter.end());
        int start = inter[0][0] , last = inter[0][1];

        for(int i=1;i<n;i++) {
            if(inter[i][0] <= last) {
                last = max(inter[i][1] , last);
            }
            else {
                result.push_back({start , last});
                start = inter[i][0] , last = inter[i][1];
            }
        }
        result.push_back({start , last});

        return result;
    }
};
