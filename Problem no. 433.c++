class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankSet(bank.begin(), bank.end());
        unordered_set<string> visited;

        int level = 0;
        queue<string> que;
        que.push(startGene);
        visited.insert(startGene);
        
        while(!que.empty()) {
            int n = que.size();

            while(n--) {
                string curr = que.front();
                que.pop();

                if(curr == endGene)
                    return level;
                
                for(char ch : "ACGT") {
                    for(int i=0;i<curr.size();i++) {
                        string neighbour = curr;
                        neighbour[i] = ch;

                        if(visited.find(neighbour) == visited.end() && bankSet.find(neighbour) != bankSet.end()) {
                            visited.insert(neighbour);
                            que.push(neighbour);
                        }
                    }
                }
            }

            level++;
        }

        return -1;
    }
};
