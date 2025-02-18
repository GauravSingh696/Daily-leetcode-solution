class Solution {
public:
    string smallestNumber(string pattern) {
        vector<int> res(pattern.size()+1);
        iota(res.begin(), res.end(), 1);

        for(int i=0 ; i<pattern.size() ; i++) {
            if(pattern[i]=='I') continue;

            else{
                int x = i;
                while(x<res.size() && pattern[x]=='D') {
                    x++;
                }
                reverse(res.begin()+i , res.begin()+x+1);
                i=x;
            }
        }
        string ans="";

        for(auto it: res) {
            char ch = it+'0';
            ans+= ch;
        }
        return ans;
    }
};
