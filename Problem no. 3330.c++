class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int result = 1;

        for(int i=0;i<n;i++) {
            int temp = i;

            while(i < n && word[i] == word[i+1]) 
                i++;

            result += i - temp;
        }

        return result;
    }
};
