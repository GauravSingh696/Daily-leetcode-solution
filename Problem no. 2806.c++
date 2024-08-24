class Solution {
public:
    int accountBalanceAfterPurchase(int pur) {
        int num = pur % 10;

        if(num < 5)
            pur -= num;
        
        else
            pur += 10 - num;
        
        return 100-pur;
    }
};
