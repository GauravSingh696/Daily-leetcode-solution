class Solution {
public:
    int countLargestGroup(int n) {
        int maxi , cnt = 0;
        vector<int> vec(37,0);
        for(int i=1 ; i<=n ; i++) {
           int x = i;
           int sum = 0; 
           while(x) {
            sum += x%10;
            x/=10;
           }
           vec[sum]++;
        }
        return count(vec.begin(), vec.end(), *max_element(vec.begin(), vec.end()));
    }
};
