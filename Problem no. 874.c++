// 05-09-2024

class Solution {
public:
    int robotSim(vector<int>& com, vector<vector<int>>& obs) {
        unordered_set<string> st;

        for(auto &it : obs)
        {
            string temp = to_string(it[0]) + " " + to_string(it[1]);
            st.insert(temp);
        }

        pair<int, int> dir = {0, 1};
        int x = 0 , y = 0;
        int result = 0;

        for(auto it : com)
        {
            if(it == -2)
                dir = {-dir.second , dir.first};
            
            else if(it == -1)
                dir = {dir.second , -dir.first};

            else
            {
                for(int step=0;step<it;step++)
                {
                    int new_x = x + dir.first;
                    int new_y = y + dir.second;

                    string next_key = to_string(new_x) + " " + to_string(new_y);
                    if(st.find(next_key) != st.end())
                        break;
                    
                    x = new_x;
                    y = new_y;
                }
            }

            result = max(result , x*x + y*y);
        }
        
        return result;
    }
};
