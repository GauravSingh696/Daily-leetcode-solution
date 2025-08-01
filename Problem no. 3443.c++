class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0;
        int east = 0, west = 0, north = 0, south = 0;

        for(int i=0;i<s.size();i++) {
            if(s[i] == 'E')         east++;
            else if(s[i] == 'W')    west++;
            else if(s[i] == 'N')    north++;
            else if(s[i] == 'S')    south++;

            int curr = abs(east - west) + abs(north - south);

            int steps = i+1;
            int wasted = steps - curr;
            int extra = 0;

            if(wasted != 0)
                extra = min(2*k, wasted);
            
            int temp = curr + extra;

            result = max(result, temp);
        }

        return result;
    }
};
