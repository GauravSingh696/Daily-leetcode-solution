class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();

        vector<pair<int , int>> v;

        for(int i=0;i<row;i++)
        {
            int c = count(mat[i].begin(), mat[i].end(), 1);

            v.push_back({c , i});
        }

        sort(v.begin(), v.end());

        vector<int> result;

        for(auto it : v)
        {
            result.push_back(it.second);

            k--;
            if(k==0)
                break;
        }

        return result;
    }
};
