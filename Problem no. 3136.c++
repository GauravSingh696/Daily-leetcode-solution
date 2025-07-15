class Solution {
public:
    bool check_vowel(char &ch) {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            return true;
        
        else
            return false;
    }

    bool isValid(string word) {
        int n = word.size();

        if(n < 3)
            return false;
        
        for(char &ch : word) {
            if(ch == '@' || ch == '#' || ch == '$')
                return false;
        }

        bool isDigit = false, isVowel = false, isConsonant = false, isUpper = false, isLower = false;

        for(char &ch : word) {
            if(ch >= '0' && ch <= '9') {
                isDigit = true;
                continue;
            }
            
            if(check_vowel(ch)) {
                isVowel = true;
                cout<<ch;
            }
            
            else
                isConsonant = true;
            
            if(ch >= 'a' && ch <= 'z')
                isUpper = true;
            
            if(ch >= 'A' && ch <= 'Z')
                isLower = true;
        }

        if((isDigit || isLower || isUpper) && isVowel && isConsonant)
            return true;
        
        return false;
    }
};
