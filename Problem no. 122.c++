// 12-10-2024

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int buy = prices[0];
        
        for(int i=1;i<prices.size();i++) {
            if(buy < prices[i])
                result += prices[i] - buy;
            
            buy = prices[i];
        }

        return result;
    }
};
