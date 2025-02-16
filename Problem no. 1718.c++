class Solution {
public:
    bool solve(int i, int n, vector<int> &result, vector<int> &occupied) {
        if(i>=result.size())
            return true;
        
        if(result[i] != -1)
            return solve(i+1, n, result, occupied);
        
        for(int num=n;num>=0;num--) {
            if(occupied[num])
                continue;
            
            occupied[num] = true;
            result[i] = num;

            if(num == 1) {
                if(solve(i+1, n, result, occupied))
                    return true;
            }

            else{
                int j = num+i;

                if(j<result.size() && result[j] == -1){
                    result[j] = num;

                    if(solve(i+1, n, result, occupied))
                        return true;
                    
                    result[j] = -1;
                }
            }

            occupied[num] = false;
            result[i] = -1;
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2*n-1 , -1);
        vector<int> occupied(n+1, false);

        solve(0, n, result, occupied);

        return result;
    }
};
