class MinStack {
public:

    stack<int> stk;
    stack<int> minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        val = min(val, minstack.empty()? val: minstack.top());
        minstack.push(val);
    }
    
    void pop() {
        stk.pop();
        minstack.pop();
    }
    
    int top() {
       return stk.top();
    }
    
    int getMin() {
        return minstack.top();
    }
};
