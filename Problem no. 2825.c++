class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0 , j = 0;
        int n1 = str1.size() , n2 = str2.size();

        if(n2 > n1)
            return false;

        while(i<n1 && j<n2) {
            char ch = str1[i];
            if(ch == 'z')
                ch = 'a';
            else
                ch++;

            if(str1[i]==str2[j] || ch==str2[j] ){
                j++;
                i++;
            }
            else {
                i++;
            }
        }

        return j==n2;
    }
};
