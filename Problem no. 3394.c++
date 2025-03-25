class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for(int i=1;i<intervals.size();i++) {
            if(intervals[i][0] < result.back()[1]) {
                result.back()[1] = max(result.back()[1] , intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> horizontal;
        vector<vector<int>> vertical;

        for(auto &it : rectangles) {
            int x1 = it[0] , y1 = it[1];
            int x2 = it[2] , y2 = it[3];

            horizontal.push_back({x1, x2});
            vertical.push_back({y1, y2});
        }

        vector<vector<int>> res1 = merge(horizontal);

        if(res1.size() >= 3)
            return true;
        
        vector<vector<int>> res2 = merge(vertical);

        return res2.size() >= 3;
    }
};
