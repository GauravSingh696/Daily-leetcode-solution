// 30-09-2024

class CustomStack {
public:
    int n;
    stack<int> st;
    vector<int> vec;

    CustomStack(int maxSize) {
        this->n = maxSize;
    }
    
    void push(int x) {
        if(st.size() < n) {
            st.push(x);
            vec.push_back(0);
        }
    }
    
    int pop() {
        if(st.empty())
            return -1;
        
        if(vec.size() > 1)
            vec[vec.size() - 2] += vec.back();
        
        int result = st.top() + vec.back();
        st.pop();
        vec.pop_back();
        return result;
    }
    
    void increment(int k, int val) {
        if(!st.empty()) {
            int idx = min(k , (int)vec.size()) - 1;
            vec[idx] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
