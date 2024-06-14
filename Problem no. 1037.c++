class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {

        int a = p[2][1] - p[1][1];  //  a = y3-y2
        int b = p[2][0] - p[1][0];  //  b = y2-y1

        int c = p[1][1] - p[0][1];  //  c = x3-x2
        int d = p[1][0] - p[0][0];  //  d = x2-x1

// this formula for finding the boomerang. (a*d != b*c)
        if(a*d != b*c)
            return true;

        return false;
    }
};
