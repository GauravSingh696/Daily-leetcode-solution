// 10-04-2024

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();

        sort(deck.begin(), deck.end());
        vector<int> result(n,0);
        int i=0,j=0;
        bool skip=false;

        while(i<n)
        {
            if(result[j]==0)
            {
                if(skip == false)
                {
                    result[j] = deck[i++];
                }

                skip = !skip;
            }

            j = (j+1)%n;
        }

        return result;
    }
};
