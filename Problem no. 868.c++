class Solution {
public:
    int binaryGap(int n){
        string bin = bitset<32> (n).to_string();
        int result = 0;
        
        for(int i=0;i<32;i++)
        {
            if(bin[i] == '1')
            {
                int first = i;
                i++;

                while(i<32)
                {
                    if(bin[i] == '1')
                        break;
                    
                    else
                        i++;
                }

                if(i < 32)
                    result = max(result , i - first);
                i--;
            }
        }

        return result;

    }
};
