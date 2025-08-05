class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for(int &it : asteroids) {
            if(it > 0)
                st.push(it);
            
            else {
                while(!st.empty() && st.top() > 0 && st.top() < -it)
                    st.pop();
                
                if(st.empty() || st.top() < 0) 
                    st.push(it);
                
                if(!st.empty() && st.top() == -it)
                    st.pop();
            }
        }

        vector<int> result(st.size());

        for(int i=st.size()-1;i>=0;i--) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};
