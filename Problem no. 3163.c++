class Solution {
public:
    string compressedString(string word) {
        string result = "";
        if(word.size() <= 1)
            return to_string(1) + word[0];

        for(int i=0;i<word.size()-1;i++) {
            int n = 1;

            while(i < word.size() && word[i] == word[i+1]) {
                n++;
                if(n>=9) {
                    result += to_string(n) + word[i];
                    n = 0;
                }

                i++;
            }

            if(n > 0) {
                result += to_string(n) + word[i];
            }
        }

        int r = result.size();
        int w = word.size();

        if(result[r-1] != word[w-1])
            result += to_string(1) + word[w-1];

        return result;
    }
};
