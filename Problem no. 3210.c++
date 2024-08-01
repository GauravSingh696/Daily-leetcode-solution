class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();

        string result = "";
        int i=0;

        for(int j=0;j<n;j++)
        {
            int temp = (i+k) % n;
            result += s[temp];
            i++;
        }
        
        return result;
    }
};
