class Solution {
public:
    bool squareIsWhite(string cor) {
        int i = cor[0] - 'a';
        int j = cor[1] - '1';

        if(i%2==1 && j%2==1)
            return false;
        
        if(i%2==1 || j%2==1)
            return true;
        
        return false;
    }
};
