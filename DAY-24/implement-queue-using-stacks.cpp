class MyQueue {
    stack<int>st,s;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st.empty()){
            s.push(st.top());
            st.pop();
        }
        
        st.push(x);
        
        // Push all from s2 to s1
        while(!s.empty()){
            st.push(s.top());
            s.pop();
        }
    }
    
    int pop() {
        int res = st.top();
        st.pop();
        return res;
        
    }
    
    int peek() {
        int res = st.top();
        return res;
    }
    
    bool empty() {
        return st.empty();
    }
};
