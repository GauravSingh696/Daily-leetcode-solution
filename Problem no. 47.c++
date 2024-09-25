class Solution {
public:
    int factorial(int n) 
    {
        return (n==1 || n==0) ? 1: n * factorial(n - 1);  
    }

    vector<vector<int>> permuteUnique(vector<int>& a) {
        vector<vector<int>>ans;
        set<vector<int>> st;

        int n=a.size();
        n=factorial(n);
        while(n--){
            next_permutation(a.begin(),a.end());
            st.insert(a);
        }

        for(auto it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};
