class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> closest_L(n, -1) , closest_R(n, -1);

        if(dominoes[0] == 'R')
            closest_L[0] = 0;

        if(dominoes[n-1] == 'L')
            closest_R[n-1] = n-1;

        // find the left closest...
        for(int i=1;i<n;i++) {
            if(dominoes[i] == 'R')
                closest_L[i] = i;
            
            if(dominoes[i] == '.' && closest_L[i-1] != -1)
                closest_L[i] = closest_L[i-1];
        }

        // find the right closest...
        for(int i=n-2;i>=0;i--) {
            if(dominoes[i] == 'L')
                closest_R[i] = i;
            
            if(closest_R[i+1] != -1 && dominoes[i] == '.')
                closest_R[i] = closest_R[i+1];
        }

        string result;

        for(int i=0;i<n;i++) {
            if(closest_R[i] != -1 && closest_L[i] != -1) {
                int dist1 = abs(i - closest_L[i]);
                int dist2 = abs(i - closest_R[i]);

                if(dist1 < dist2)
                    result += 'R';
                else if(dist1 > dist2)
                    result += 'L';
                else
                    result += '.';
            }

            else if(closest_R[i] == -1 && closest_L[i] != -1)
                result += 'R';

            else if(closest_R[i] != -1 && closest_L[i] == -1)
                result += 'L';

            else
                result += '.';
        }

        return result;
    }
};
