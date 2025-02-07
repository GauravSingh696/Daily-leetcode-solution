class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int,int> ball_map;
        unordered_map<int, int> color_map;

        for(auto it : queries) {
            int ball  = it[0];
            int color = it[1];

            if(ball_map.find(ball) != ball_map.end()) {
                int prev_color = ball_map[ball];
                color_map[prev_color]--;

                if(color_map[prev_color] == 0)
                    color_map.erase(prev_color);
            }

            color_map[color]++;
            ball_map[ball] = color;
            result.push_back(color_map.size());
        }

        return result;
    }
};
