class MinStack {
    stack<pair<int,int>> s;
    int minValue;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int val) {
        int minValue = INT_MAX;
        if(s.empty()){
            s.push(make_pair(val,val));
        } else {
            minValue = min(s.top().second, val);
            s.push(make_pair(val, minValue));
        }
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

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */