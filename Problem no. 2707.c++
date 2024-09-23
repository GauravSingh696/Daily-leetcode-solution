// 23-09-2024

class Solution {
public:
    int minExtraChar(string s, vector<string>& dic) {
        int n = s.size();
        unordered_set<string> st(begin(dic), end(dic));

        vector<int> result(n+1 , 0);

        for(int i=n-1;i>=0;i--) {
            result[i] = 1 + result[i+1];

            for(int j=i;j<n;j++) {
                string curr = s.substr(i , j-i+1);

                if(st.count(curr)) {
                    result[i] = min(result[i] , result[j+1]);
                }
            }
        }

        return result[0];
    }
};
