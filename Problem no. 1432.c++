class Solution {
public:
    int maxDiff(int num) {
        string ans = to_string(num);
        char ch = '$';

        for(const char &it : ans) {
            if(it!='9') {
                ch = it;
                break;
            }
        }
        string max = ans, min = ans;
        if(ch=='$') goto THEN;

        for(int i=0 ; i<ans.size() ; i++) {
            if(ans[i]==ch) {
                max[i] = '9';
            }
        } 

        THEN:
        unordered_set<char> st(ans.begin(), ans.end());
        int i=0;
        while(ans[i]=='1') i++;
        char c='0';
        ch = '$';
        if(st.size()==1) c = '1';
        for( ; i<ans.size() ; i++) {
            if(ans[i] >='2') {
                if(i==0) c = '1';
                ch = ans[i];
                break;
            }
        }

        if(ch !='$')
            for(int i=0 ; i<ans.size() ; i++) {
                if(ans[i]==ch) {
                    min[i] = c;
                }
            }
        int maxi = stoi(max), mini = stoi(min);

        return maxi-mini;
    }
};
