class Solution {
public:
    string getHappyString(int n, int k) {
        queue<string> que;
        que.push("a");
        que.push("b");
        que.push("c");

        vector<string> vec;

        while(!que.empty()) {
            string str = que.front();
            que.pop();

            if(str.size() == n) {
                vec.push_back(str);
                continue;
            }

            for(auto &it : {'a','b','c'}) {
                if(str.back() != it) {
                    que.push(str + it);
                }
            }
        }

        return vec.size()<k ? "" : vec[k-1] ;
    }
};
