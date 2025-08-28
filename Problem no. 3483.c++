class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> vec(10, 0);
        vector<int> result;

        for(auto &it : digits) {
            vec[it]++;
        }

        for(int i=1;i<=9;i++) {
            if(vec[i]==0)
                continue;
            
            vec[i]--;

            for(int j=0;j<=9;j++) {
                if(vec[j]==0)
                    continue;
                
                vec[j]--;

                for(int k=0;k<=8;k+=2) {
                    if(vec[k]==0)
                        continue;
                    
                    vec[k]--;

                    int val = i*100 + j*10 + k;

                    result.push_back(val);

                    vec[k]++;
                }

                vec[j]++;
            }

            vec[i]++;
        }

        return result.size();
    }
};
