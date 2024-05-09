class Solution {
public:
    bool judgeCircle(string moves) {
        int len = moves.length();
        int left=0, right=0, up=0, down=0;

        for(int i=0;i<len;i++)
        {
            if(moves[i]=='L')
                left += 1;
            
            else if(moves[i]=='R')
                right += 1;
            
            else if(moves[i]=='U')
                up += 1;
            
            else
                down += 1;
        }

        if((right-left)==0 && (down-up)==0)
            return true;
        
        else
            return false;
    }
};
