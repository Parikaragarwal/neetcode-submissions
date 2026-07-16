class Solution {
public:
    bool isOperator(string &t){
        return (t=="+" || t=="-" || t=="/" || t=="*");
    }
    int evaluate(int a,int b,string &t){
        if(t=="*"){
            return a*b;
        }else if(t=="+"){
            return a+b;
        }else if(t=="-"){
            return a-b;
        }else if(t=="/"){
            return a/b;
        }
        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string t: tokens){
            if(!isOperator(t)){
                s.push(stoi(t));
            }else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(evaluate(b,a,t));
            }
        }
        return s.top();
    }
};
