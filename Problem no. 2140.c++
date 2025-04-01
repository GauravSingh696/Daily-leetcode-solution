class Solution {
public:
    vector<long long> vec;

    long long solve(vector<vector<int>>& ques, int idx) {
        if(idx >= ques.size())
            return 0;
        
        if(vec[idx] != -1)
            return vec[idx];
        
        long long take = ques[idx][0] + solve(ques, idx+ques[idx][1]+1);
        long long not_take = solve(ques, idx+1);

        return vec[idx] = max(take , not_take);
    }

    long long mostPoints(vector<vector<int>>& ques) {
        vec.assign(ques.size()+1, -1);

        return solve(ques, 0);
    }
};
