// first approach

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);

        string temp , result = "";

        while(ss >> temp)
        {
            result = temp + " " + result;
        }

        result.pop_back();

        return result;
    }
};



// second approach

class Solution {
public:
    string reverseWords(string s) {
        int i=0, r=0, l=0;
        int n = s.size();
        reverse(s.begin(), s.end());

        while(i<n)
        {
            while(i<n && s[i]!=' ')
                s[r++] = s[i++];
            
            if(l < r)
            {
                reverse(s.begin()+l , s.begin()+r);

                s[r++] = ' ';

                l = r;                
            }

            i++;
        }

        return s.substr(0,r-1);
    }
};
