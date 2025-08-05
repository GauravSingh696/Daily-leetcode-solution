class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int result = 0;
        
        for(int i=0;i<fruits.size();i++) {
            int j = 0;

            for(;j<fruits.size();j++) {
                if(baskets[j] >= fruits[i]) {
                    baskets[j] = -1;
                    break;
                }
            }

            if(j == fruits.size())
                result++;
        }

        return result;
    }
};
