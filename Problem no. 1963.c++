// 08-10-2024

class Solution {
public:
    static int minSwaps(string& s) {
        int p=0;
        for(char c: s){
            p+=(c=='[')-(c==']');
            if (p<0)
                p=0;
        }
        return (p+1)/2;
    }
};
