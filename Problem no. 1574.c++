// 15-11-2024

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;

        while(left<n-1 && arr[left]<=arr[left+1]) {
            left++;
        }

        if(left == n-1)
            return 0;

        int right = n-1;

        while(right>0 && arr[right]>=arr[right-1]) {
            right--;
        }

        int result = min(n-left-1 , right);
        int i=0;

        while(i<=left && right<n) {
            if(arr[i]<=arr[right]) {
                result = min(result, right-i-1);
                i++;
            }
            else
                right++;
        }

        return result;
    }
};
