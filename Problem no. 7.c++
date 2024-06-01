class Solution {
public:
    int reverse(int x) {
        while(x)
        {
            int rem = x%10;
            if(rem != 0)
                break;
            
            x /= 10;
        }

        long long int result = 0;

        while(x)
        {
            int rem = x%10;
            result = result * 10 + rem;
            x /= 10;
        }

        if(result > INT_MAX || result < INT_MIN)
            return 0;

        return result;
    }
};
