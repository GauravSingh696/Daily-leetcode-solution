class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int F=0 , T=0 ;
        for(int i=0 ; i<bills.size() ; i++)
        {
            if(bills[i]==5){
                F++;
            }

            else if(bills[i]==10){
                if(F<1){
                    return false;
                }

                else{
                    T++;
                    F--;
                }
            }

            else{
                if(T>=1 && F>=1)
                {                    
                    T--;
                    F--;
                }

                else if(F>=3)
                {
                    F-=3;
                }

                else{
                    return false;
                }
            }
        }
        return true;
    }
};
