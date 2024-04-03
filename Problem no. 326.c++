class Solution {
public:
    bool isPowerOfThree(int n) {
        long long result = pow(3,30);

        if(n<=0)
            return false;
        
        if(result%n==0)
            return true;
        
        return false;
    }
};
