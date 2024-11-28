class Solution {
public:
    vector<int> finalPrices(vector<int>& p) {
        int cost=0;

        for(int i=0;i<p.size()-1;i++){
            for(int j=i+1;j<p.size();j++){
                if(p[j]<=p[i]){
                    p[i]-=p[j];
                    break;
                }
            }
        }
        return p;
    }
};
