class Solution {
public:
    int dayOfYear(string date) {
        int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
        int year[3]={0};
        int idx=0;
        int x=0;
        for(auto it:date)
        {
            if(it=='-')
            {
                year[idx++]=x;
                x=0;
            }

            else
            {
                x=x*10+(it-'0');
            }
        }
        year[idx]=x;
        if ((year[0] % 4 == 0 && year[0] % 100 != 0) || year[0] % 400 == 0) {
            arr[1]=29;
        }
        idx=0;
        int sum=0;
        while(idx+1<year[1])
        {
            sum+=arr[idx++];
        }
        sum+=year[2];

        return sum;
    }
};
