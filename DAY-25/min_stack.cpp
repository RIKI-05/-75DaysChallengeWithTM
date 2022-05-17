
class MinStack {
public:
stack<pair<int,int>>s;
    MinStack() {
        
    }
    
    void push(int val) {
        int minele = s.empty()?val:min(s.top().second,val);
        s.push({val,minele});
       
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }

};

