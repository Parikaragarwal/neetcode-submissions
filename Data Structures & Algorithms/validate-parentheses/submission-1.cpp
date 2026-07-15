class Solution {
public:
    char oppbracket(char ch){
       if(ch==')'){
        return '(';
       }
       if(ch=='}'){
        return '{';
       }
       if(ch==']'){
        return '[';
       }
       return '0';
    }
    bool isValid(string s) {
        if(s.size()%2!=0){
            return false;
        }
        stack<char> st;
        for(char c:s){
            char ob = oppbracket(c);
            if(ob=='0'){
                st.push(c);
            }else if(!st.empty() && st.top()==ob){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
