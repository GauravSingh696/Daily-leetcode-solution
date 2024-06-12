class Solution {
public:
    int bitwiseComplement(int n) {
        string st = bitset<32> (n).to_string();

        if(n==1)
            return 0;

        if(n==0)
            return 1;

        int i=0;

        for(i=0;i<32;i++)
        {
            if(st[i]!='0')
                break;
        }

        for(int j=i;j<32;j++)
        {
            if(st[j]=='1')
                st[j] = '0';

            else
                st[j] = '1';
        }

        int a = 0;
        int val = 0;

        for(int j=31;j>=i;j--)
        {
            val = val + (st[j] - 48) * pow(2, a);
            a++;
        }

        return val;
    }
};
