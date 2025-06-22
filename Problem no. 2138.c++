class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> result;

        for(int i=0;i<n;i+=k) {
            string str;
            int j = i;

            for(;j<k+i && j<n;j++) {
                str.push_back(s[j]);
            }

            while(j<k+i) {
                str.push_back(fill);
                j++;
            }

            result.push_back(str);
        }

        return result;
    }
};
