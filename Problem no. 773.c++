// 25-11-2024

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string st = "";

        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[0].size();j++) {
                st += to_string(board[i][j]);
            }
        }

        string target = "123450";
        unordered_map<int, vector<int>> mp;
        mp[0] = {1, 3};
        mp[1] = {0, 2, 4};
        mp[2] = {1, 5};
        mp[3] = {0, 4};
        mp[4] = {1, 3, 5};
        mp[5] = {2, 4};

        queue<string> que;
        que.push(st);

        unordered_set<string> visited;
        visited.insert(st);
        int level = 0;

        while(!que.empty()) {
            int n = que.size();

            while(n--) {
                string curr = que.front();
                que.pop();

                if(curr == target)
                    return level;
                
                int zero_index = curr.find('0');
                
                for(auto it : mp[zero_index]) {
                    string new_string = curr;
                    swap(new_string[it] , new_string[zero_index]);

                    if(visited.find(new_string) == visited.end()) {
                        visited.insert(new_string);
                        que.push(new_string);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};
