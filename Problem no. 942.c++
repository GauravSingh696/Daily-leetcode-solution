class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> result;
        int a = 0;
        int b = s.length();

        for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'I')
                result.push_back(a++);
            
            else
                result.push_back(b--);
        }

        if(a<b)
            result.push_back(a++);

        else
        {
            result.push_back(b--);
        }

        return result;
    }
};
