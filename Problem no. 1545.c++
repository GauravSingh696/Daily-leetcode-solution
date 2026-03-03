class Solution {
  public:
    char findKthBit(int n, int k) {
        string ans="0";

        while(n-- && k>ans.length()){
            string temp=ans;
            reverse(temp.begin(),temp.end());

            for(int i=0;i<temp.size();i++) {
                if(temp[i]=='0') {
                    temp[i]='1';
                } else {
                    temp[i]='0';
                }  
            }

            ans+="1"+temp;
        }

        return ans[k-1];
    }
};
