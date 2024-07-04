class Solution {
public:
    string sortString(string s) {
        int arr[26] = {0};

        for(int i=0;i<s.size();i++)
        {
            arr[s[i]-'a']++;
        }

        string result = "";
        
        while(true)
        {
            for(int i=0;i<26;i++)
            {
                if(arr[i] > 0)
                {
                    result += i + 'a';
                    arr[i]--;
                }
            }

            for(int i=25;i>=0;i--)
            {
                if(arr[i] > 0)
                {
                    result += i + 'a';
                    arr[i]--;
                }
            }

            bool flag = false;

            for(int i=0;i<26;i++)
            {
                if(arr[i] > 0)
                    flag = true;
            }

            if(flag == false)
                break;
        }

        return result;

    }
};
