class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int len = s.length();
        int count = 1;
        int start = 0;
        int i, end = 0;
        vector<vector<int>> result;
        vector<int> temp;

        for(i=1;i<len;i++)
        {
            if(s[i]==s[i-1])
            {
                if(count==1)
                    start = i-1;

                count++;
            }

            else
            {
                if(count>2)
                {
                    end = i-1;
                    temp.push_back(start);
                    temp.push_back(end);
                    result.push_back(temp);
                    temp.clear();

                    count = 1;
                }

                else
                {
                    count = 1;
                }
            }
        }

        if(count > 2)
        {
            end = i-1;

            temp.push_back(start);
            temp.push_back(end);
            result.push_back(temp);

        }

        return result;
    }
};
