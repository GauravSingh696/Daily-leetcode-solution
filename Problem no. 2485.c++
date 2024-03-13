//  13-03-2024

class Solution {
public:
    int pivotInteger(int n) {

        for(int i=1;i<=n;i++)
        {
            int add1=0,add2=0;
            for(int j=i;j>=1;j--)
            {
                add1 += j;
            }

            for(int j=i;j<=n;j++)
            {
                add2 += j;
            }

            if(add1==add2)
            {
                return i;
            }
        }
        return -1;
    }
};
