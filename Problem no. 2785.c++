class Solution {
public:
    bool isVowels(char s){
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'
            || s == 'A' || s == 'E' || s == 'I' || s == 'O' || s == 'U'){
              return true;
        }
        return false;
    }
    
    string sortVowels(string s) {
        vector<char> vol;

        for(auto ch : s){
            if(isVowels(ch)){
                vol.push_back(ch);
            }
        }

        sort(vol.begin(),vol.end());
        int j = 0;

        for(int i=0; i<s.size(); i++){
            if(isVowels(s[i])){
                s[i] = vol[j++];
            }
        }

        return s;
    }
};
