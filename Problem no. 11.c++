class Solution {
public:
    int maxArea(vector<int>& hg) {
        int left = 0 , right = hg.size()-1;
        int result = 0;

        while(left < right)
        {
            if(hg[left] == hg[right])
            {
                result = max(result , (right-left) * hg[right]);
                left++;     right--;
            }

            else if(hg[left] > hg[right])
            {
                result = max(result , (right-left) * min(hg[left] , hg[right]));
                right--;
            }

            else
            {
                result = max(result , (right-left) * min(hg[left] , hg[right]));
                left++;
            }
        }

        return result;

    }
};
