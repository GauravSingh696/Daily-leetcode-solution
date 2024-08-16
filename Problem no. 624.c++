// 16-08-2024

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_dis = INT_MIN;
        int min_ = arrays[0].front();
        int max_ = arrays[0].back();

        for(int i=1;i<arrays.size();i++)
        {
            max_dis = max({max_dis, abs(arrays[i].back() - min_) , abs(arrays[i].front() - max_)});
            min_ = min(min_ , arrays[i].front());
            max_ = max(max_ , arrays[i].back());
        }

        return max_dis;
    }
};
