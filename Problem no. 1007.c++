class Solution {
public:
    int solve(int num, vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        int top_cnt = 0 , bottom_cnt = 0;

        for(int i=0;i<n;i++) {
            if(tops[i] != num && bottoms[i] != num) {
                return INT_MAX;
            }

            if(tops[i] != num)
                top_cnt++;
            
            else if(bottoms[i] != num)
                bottom_cnt++;
        }
        
        return min(top_cnt , bottom_cnt);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;

        for(int i=1;i<=6;i++) {
            int temp = solve(i, tops, bottoms);

            if(temp != INT_MAX)
                result = min(result, temp);
        }

        return result==INT_MAX ? -1 : result ;
    }
};
