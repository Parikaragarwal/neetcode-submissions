class MinStack {
public:
        stack<int> as;
        stack<int> ms;
    MinStack() {
    }
    
    void push(int val) {
        as.push(val);
        if(ms.empty() || ms.top()>=val){
            ms.push(val);
        }
    }
    
    void pop() {
        int el = as.top();
        as.pop();
        if(el==ms.top()){
            ms.pop();
        }
    }
    
    int top() {
        return as.top();
    }
    
    int getMin() {
        return ms.top();
    }
};
