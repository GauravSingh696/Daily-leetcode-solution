// 04-05-2024

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
         int count=0;
        int j=people.size()-1;
        int i=0;
        sort(people.begin(),people.end());
        while(i<=j){
            if((people[i]+people[j])<=limit )
            {
                count=count+1;
                j--;
                i++;
            }

            else if(people[j]<=limit){ 
                count=count+1;
                j--;
            }
        }
        return count;

    }
};
