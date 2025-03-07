class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> result;

        if(left==1)
            left++;

        for(int i=left; i<=right; i++) {
            if(isPrime(i)) {
                result.push_back(i);
            }
        }

        if(result.size() < 2)
            return {-1,-1};

        pair<int,pair<int,int>> pr = {INT_MAX,{INT_MAX,INT_MAX}};

        for(int i=0;i<result.size()-1;i++) {
            if(result[i+1]-result[i] < pr.first) {
                pr = {result[i+1]-result[i] , {result[i] , result[i+1]}};
            }
        }

        return {pr.second.first , pr.second.second};
    }
};
