class Solution {
public:
    int mod = 1e9+7;

    long long find_power(long long a, long long b) {
        if(b==0)
            return 1;
        
        long long half = find_power(a, b/2);
        
        long long result = (half * half) % mod;

        if(b%2 == 1) {
            result = (result * a) % mod;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        return (find_power(5, (n+1)/2) * find_power(4, n/2)) % mod;
    }
};
