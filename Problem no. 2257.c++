class Solution {
public:
    int row , col;
    void solve(vector<vector<char>> &vec , int i , int j) {
        int count = 0;
        
        // right
        for(int a=j+1;a<col;a++) {
            if(vec[i][a] == 'w' || vec[i][a] == 'g')
                break;
            else
                vec[i][a] = '0';
            count = 1;
        }

        count = 0;

        // bottom
        for(int a=i+1;a<row;a++) {
            if(vec[a][j] == 'w' || vec[a][j] == 'g')
                break;
            else
                vec[a][j] = '0';
            count = 1;
        }

        count = 0;

        // top
        for(int a=i-1;a>=0;a--) {
            if(vec[a][j] == 'w' || vec[a][j] == 'g')
                break;
            else
                vec[a][j] = '0';
            count = 1;
        }

        count = 0;

        // left
        for(int a=j-1;a>=0;a--) {
            if(vec[i][a] == 'w' || vec[i][a] == 'g')
                break;
            else
                vec[i][a] = '0';
            count = 1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> vec(m , vector<char>(n, '1'));
        row = m , col = n;

        for(auto it : walls) {
            vec[it[0]][it[1]] =  'w';
        }

        for(auto it : guards) {
            vec[it[0]][it[1]] =  'g';
        }

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(vec[i][j] == 'g') {
                    solve(vec , i , j);
                }
            }
        }

        int unguarded = 0;

        for(auto it : vec) {
            unguarded += count(it.begin(), it.end(), '1');
        }

        return unguarded;
    }
};
