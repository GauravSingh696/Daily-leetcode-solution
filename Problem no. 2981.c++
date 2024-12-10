class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<string, int> mp;

        for(int i=0;i<n;i++) {
            string temp;
            
            for(int j=i;j<n;j++) {
                if(temp.empty() || temp.back()==s[j]) {
                    temp.push_back(s[j]);
                    mp[temp]++;
                }
                
                else 
                    break;
            }
        }

        int result = 0;

        for(auto it : mp) {
            string str = it.first;
            int count = it.second;

            if(count >= 3 && str.size() > result) 
                result = str.size();
        }

        return result == 0 ? -1 : result ;
    }
};
