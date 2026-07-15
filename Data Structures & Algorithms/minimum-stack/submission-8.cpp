class MinStack {
public:
    // stack<int> as;
    // stack<int> ms;
    
    // MinStack() {
    // }
    
    // void push(int val) {
    //     as.push(val);
    //     if(ms.empty() || ms.top()>=val){
    //         ms.push(val);
    //     }
    // }
    
    // void pop() {
    //     int el = as.top();
    //     as.pop();
    //     if(el==ms.top()){
    //         ms.pop();
    //     }
    // }
    
    // int top() {
    //     return as.top();
    // }
    
    // int getMin() {
    //     return ms.top();
    // }
    stack<long long> s;
    long long min;
    

    MinStack() {
        min=INT_MAX;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(0);
            min=val;
            return;
        }
        s.push(val-min);
        if(val<min){
          min = val;
        }
    }
    
    void pop() {
        long long el = s.top();
        s.pop();
        if(el<0){
            min = min-el;
        }
        if(s.empty()){
            min=INT_MAX;
        }
    }
    
    int top() {
        long long el = s.top();
        if(s.top()>=0){
            return el+min;
        }else{
            return min;
        }
    }
    
    int getMin() {
        return (int)min;
    }
};
