// 09-03-2024

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        //    first approach of solving the question.
/*        unordered_set<int> st(begin(nums1),end(nums1));

        for(int &num : nums2)
        {
            if(st.find(num)!=st.end(num))
                return num;
        }
        return -1;  */


        //    second approach of solving the question.
        int a=nums1.size();
        int b=nums2.size();

        int i=0,j=0;
        while(i<a && j<b)
        {
            if(nums1[i]==nums2[j])
                return nums1[i];
            
            else if(nums1[i]<nums2[j])
                i++;

            else
                j++;
        }
        return -1;
    }
};
