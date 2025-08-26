class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_area = 0, dia = 0;

        for(auto it : dimensions) {
            int curr_dia = it[0]*it[0] + it[1]*it[1];

            if(dia < curr_dia) {
                dia = curr_dia;
                max_area = it[0]*it[1];
            } else if(dia == curr_dia) {
                max_area = max(max_area, it[0]*it[1]);
            }
        }

        return max_area;
    }
};
