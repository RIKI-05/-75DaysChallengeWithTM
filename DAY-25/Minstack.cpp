class MinStack {
public:
    stack<int>st;
    stack<int>minstck;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minstck.empty())
        {
            minstck.push(val);
        }
        else
        {
            if(val<=minstck.top())
                minstck.push(val);
        }
        
    }
    
    void pop() {
        if(st.empty())return;
        if(minstck.top()==st.top())
            minstck.pop();
        st.pop();
    }
    
    int top() {
        if(st.empty())return -1;
        return st.top();
        
    }
    
    int getMin() {
        if(st.empty())return -1;
        return minstck.top();
        
    }
};
