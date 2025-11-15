class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> countOne(n, 0);
        countOne[0] = (s[0] == '1') ? 1 : 0 ;

        for(int i=1;i<n;i++) {
            countOne[i] = countOne[i-1] + ((s[i] == '1') ? 1 : 0);
        }

        int result = 0;

        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int one = countOne[j] - (i-1 >= 0 ? countOne[i-1] : 0);
                int zero = (j-i+1) - one;

                if(zero*zero > one) {
                    int wasteIdx = (zero * zero) - one;
                    j += wasteIdx - 1;
                } else if((zero*zero) == one) {
                    result += 1;
                } else {
                    result += 1;
                    
                    int k = sqrt(one) - zero;
                    int next = j + k;

                    if(next >= n) {
                        result += (n-j-1);
                        break;
                    } else {
                        result += k;
                    }

                    j = next;
                }
            }
        }

        return result;
    }
};
