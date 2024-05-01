// 01-04-2024

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.length();

        for(int i=0;i<n;i++)
        {
            if(ch==word[i])
            {
                reverse(word.begin(), word.begin()+i+1);
                break;
            }
        }

        return word;
    }
};
