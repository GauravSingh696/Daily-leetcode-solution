class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int res1 = 0;
        int res2 = 0;

        int r = red;
        int b = blue;

        int i = 1;

        while(i <= blue || i <= red)
        {
            if(i%2 != 0)
            {
                if(blue < i)
                    break;
                blue -= i;
                res1++;
            }

            else
            {
                if(red < i)
                    break;

                red -= i;
                res1++;
            }

            i++;
        }

        i = 1;

        while(i <= b || i <= r)
        {
            if(i%2 == 0)
            {
                if(b < i)
                    break;

                b -= i;
                res2++;
            }

            else
            {
                if(r < i)
                    break;

                r -= i;
                res2++;
            }

            i++;
        }

        return max(res1, res2);
    }
};
