class Solution {
public:
    bool hasAlternatingBits(int n) {
        string st = bitset<32> (n).to_string();
        int i;

        for(i=0;i<32;i++)
        {
            if(st[i]!='0')
                break;
        }

        if(st[i]=='0')
        {
            for(int j=i;j<32;j=j+2)
            {
                if(st[j]!='0')
                    return false;
            }

            for(int j=i+1;j<32;j=j+2)
            {
                if(st[j]!='1')
                    return false;
            }

            return true;
        }

        else
        {
            for(int j=i;j<32;j=j+2)
            {
                if(st[j]!='1')
                    return false;
            }

            for(int j=i+1;j<32;j=j+2)
            {
                if(st[j]!='0')
                    return false;
            }

            return true;
        }
    }
};
