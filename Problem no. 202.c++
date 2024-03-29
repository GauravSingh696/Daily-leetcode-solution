class Solution {
public:
    bool isHappy(int n) {
        long long int sum;
        while(n>5)
        {
            sum=0;
            while(n)
            {
                int rem=n%10;
                sum += rem*rem;
                n=n/10;
            }

            n = sum;
        }
        if(n==1)
            return true;
        else
            return false;
    }
};
