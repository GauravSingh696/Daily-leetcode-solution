class Solution {
public:
    int factorial(int n) {
        return (n==1 || n==0) ? 1: n * factorial(n - 1);  
    }

    vector<vector<int>> permute(vector<int>& a) {
        vector<vector<int>>ans;
        int n=a.size();
        n=factorial(n);

        while(n--) {
            next_permutation(a.begin(),a.end());
            ans.push_back(a);
        }
        
        return ans;
    }
};  
