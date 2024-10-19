// 19-10-2024

class Solution {
public:
    char findKthBit(int n, int k) {
        string s1 = "0";

        if(n==1) {
            return s1[0];
        }

        n--;

        while(n--) {
            string rev = s1;
            reverse(begin(rev) , end(rev));

            for(int i=0;i<=s1.size()-1;i++) {
                if(rev[i] == '0')
                    rev[i] = '1';
                else
                    rev[i] = '0';
            }

            s1 = s1 + '1' + rev;
        }

        return s1[k-1];
    }
};
