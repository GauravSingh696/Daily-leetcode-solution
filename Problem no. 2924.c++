class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> res(n,0);
        for(auto it : edges) {
            res[it[1]]++;
        }
        int ans=0 , cnt=0;
        for(int i=0 ; i<n ; i++) {
            if(res[i]==0) {
                ans=i;
                cnt++;
            }
        }
        return cnt==1?ans:-1;
    }
};
