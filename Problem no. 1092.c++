class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> t(n1+1, vector<int> (n2+1));

        for(int i=0;i<n1+1;i++) {
            for(int j=0;j<n2+1;j++) {
                if(i==0 || j==0)
                    t[i][j] = i+j;
                
                else if(s1[i-1] == s2[j-1])
                    t[i][j] = 1 + t[i-1][j-1];
                
                else
                    t[i][j] = 1 + min(t[i-1][j] , t[i][j-1]);
            }
        }

        string result;
        int i=n1 , j=n2;

        while(i>0 && j>0) {
            if(s1[i-1] == s2[j-1]) {
                result.push_back(s1[i-1]);
                i-- , j--;
            }

            else {
                if(t[i-1][j] < t[i][j-1]) {
                    result.push_back(s1[i-1]);
                    i--;
                }
                else {
                    result.push_back(s2[j-1]);
                    j--;
                }
            }
        }

        while(i>0) {
            result.push_back(s1[i-1]);
            i--;
        }

        while(j>0) {
            result.push_back(s2[j-1]);
            j--;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
