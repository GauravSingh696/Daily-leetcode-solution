class Solution {
public:
    vector<int> sumZero(int n) {
        int x=-(n/2);
        bool flag=false;
        if(n%2==0)
            flag=true;
        vector<int> result;
        while(n)
        {
            if(flag && x==0)
            {
                x++;
                continue;
            }
            result.push_back(x++);
            n--;
        }
        return result;
    }
};
