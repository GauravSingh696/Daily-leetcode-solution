// 03-06-2024

class Solution {
public:
    int appendCharacters(string s, string t) {
        int l1=0 , l2=0 , n=s.size() , m=t.size();
 
        while(l1<n && l2<m)
        {
            if(s[l1]==t[l2])
            {
                l1++;
                l2++;
            }

            else
            {
                l1++; 
            }
        }
        return  m-l2;
    }
};
