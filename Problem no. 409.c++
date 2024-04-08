class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;

        for(auto ch : s)
        {
            count[ch]++;
        }

        int result=0;
        bool odd_found=false;
        for(auto &ch : count)
        {
            if(ch.second%2 == 0)
                result += ch.second;
            
            else
            {
                odd_found=true;
                result += ch.second-1;
            }
        }

        if(odd_found)
            return ++result;
        
        return result;
    }
};
