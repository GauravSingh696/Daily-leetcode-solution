class Solution {
public:
    string clearDigits(string s) {
        int n = s.length();
        stack<char> str;

        for(auto it : s)
        {
            if(it >='a' && it <='z')
                str.push(it);

            else
                str.pop();
        }

        s = "";
        int size = str.size();

        for(int i=0;i<size;i++)
        {
            s = str.top() + s;
            str.pop();
        }

        return s;
    }
};
