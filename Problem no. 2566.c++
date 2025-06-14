class Solution {
public:
    int minMaxDifference(int num) {
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
        for(const char &it : ans) {
            if(it!='0') {
                ch = it;
                break;
            }
        }

        for(int i=0 ; i<ans.size() ; i++) {
            if(ans[i]==ch) {
                min[i] = '0';
            }
        } 
        int maxi = stoi(max), mini = stoi(min);

        return maxi-mini;
    }
};
