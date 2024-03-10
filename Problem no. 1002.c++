class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> check(26,INT_MAX);
        for(auto it:words)
        {
            vector<int> temp(26,0);
            for(auto t:it)
            {
                temp[t-'a']++;
            }

            for(int i=0;i<26;i++)
            {
                check[i]=min(check[i],temp[i]);
            }
        }

        vector<string> result;
        for(int i=0;i<26;i++)
        {
            while(check[i]--)
            {
                result.push_back(string(1,i+'a'));
            }
        }
        return result;
    
    }
};
