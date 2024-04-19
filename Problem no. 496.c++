class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0; j<nums2.size() ; j++)
            {
                if(nums1[i]==nums2[j])
                {
                    j=j+1;
                    while(j<nums2.size())
                    {
                        if(nums1[i]<nums2[j])
                        {
                            v.push_back(nums2[j]);
                            break;
                        }
                        j++;
                    }
                    int temp=-1;

                    if(j==nums2.size())
                        v.push_back(temp);
                    
                    break;
                }
            }
        }
        return v;
    }
};
