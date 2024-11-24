class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long result = 0;
        int negative_count = 0;
        int min_abs_val = INT_MAX;
        
        for(auto it : matrix) {
            for(auto i : it) {
                if(i < 0) {
                    negative_count++;
                }
                min_abs_val = min(min_abs_val , abs(i));
                result += abs(i);
            }
        }

        cout<<negative_count<<" "<<min_abs_val<<result<<endl;

        if(negative_count%2 == 0)
            return result;
        
        return result - 2*min_abs_val;
    }
};
