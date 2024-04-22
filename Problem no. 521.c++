class Solution {
public:
    int findLUSlength(string a, string b) {
        int count=0;
        int m=a.length();
        int n=b.length();

        if(a==b)
            return -1;

        return m>n ? m : n; 
    }
};
