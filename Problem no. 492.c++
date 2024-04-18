class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> v;

        for(int i=1;i<=sqrt(area);i++)
        {
            if(area%i == 0)
            {
                v = { area/i , i};
            }
        }

        return v;
    }
};
