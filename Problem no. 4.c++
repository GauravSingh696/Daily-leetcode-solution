class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        
        for(int i=0;i<n;i++)
        {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(), nums1.end());

        int s = nums1.size();

        if(s%2 == 0)
        {
            int rem = s/2;
            double result= (nums1[rem] + nums1[rem-1]) / (double)2;

            return result;
        }

        double ans = nums1[s/2];
        return ans;
        
    }
};
