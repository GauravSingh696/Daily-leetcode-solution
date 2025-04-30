class Solution {
public:
    bool solve(vector<int> &piles, int h, int mid) {
        int hours = 0;

        for(auto &it : piles) {
            hours += it / mid;

            if(it%mid != 0)
                hours++;
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(solve(piles, h, mid)) 
                right = mid;
            
            else 
                left = mid+1;
        }

        return left;
    }
};
