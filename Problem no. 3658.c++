class Solution {
public:
    int gcd(int a, int b) {
        if(b==0)
            return a;

        return gcd(b, a%b);
    }
    
    int gcdOfOddEvenSums(int n) {
        int even = 2;
        int odd  = 1;
        int sum1 = 0, sum2 = 0;

        for(int i=1;i<n;i++) {
            sum1 += even;
            sum2 += odd;
            even += 2;
            odd  += 2;
        }

        sum1 += even , sum2 += odd;

        return gcd(sum1, sum2);
    }
};
