class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0 , j=0;
        while(i<name.size())
        {
            int c=0,y=0;
            if(name[i]==typed[j])
            {
                while(typed[j]==name[i])
                {
                    c++;
                    j++;
                }
                
                while(name[i]==name[i+1])
                {
                    y++;
                    i++;
                }
                
                i++;
                y++;
                if(c<y)
                    return false;
                
            }
            else
                return false;
        }

        while(j<typed.size())
        {
            if(typed[j]!=name[i])
                return false;
            j++;
        }
        return true;
    }
};
