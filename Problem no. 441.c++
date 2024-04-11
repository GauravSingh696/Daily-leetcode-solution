class Solution {
public:
    int arrangeCoins(int n) {
        int i=1;
        int result=0;

        while(n>=i)
        {
            n -= i;
            result++;
            i++;
        }

        return result;
    }
};
