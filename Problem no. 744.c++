class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        sort(letters.begin(), letters.end());
        bool flag = false;
        
        for(int i=0;i<letters.size();i++) {
            if(letters[i]>target){
                return letters[i];
            }
        }

        return letters[0];
    }
};
