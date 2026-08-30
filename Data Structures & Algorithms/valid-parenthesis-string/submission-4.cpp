class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int low = 0;
        int high = 0;
        for(char ch:s){
            if(ch=='('){
                low++;
                high++;
            }else if(ch==')'){
                low= max(0,low-1);
                high--;
            }else{
                low = max(0,low-1);
                high++;
            }
            if(high<0){
                return false;
            }
        }
        
        if(high<0 || low!=0){
            return false;
        }else{
            return true;
        }
        // stack<int> open;
        // stack<int> star;
        // int n = s.size();
        // for(int i=0;i<n;i++){
        //     char ch = s[i];
        //     if(ch=='('){
        //         open.push(i);
        //     }else if(ch=='*'){
        //         star.push(i);
        //     }else{
        //         if(!open.empty()){
        //             open.pop();
        //         }else if(!star.empty()){
        //             star.pop();
        //         }else{
        //             return false;
        //         }
        //     }
        // }
        // while(!open.empty() && !star.empty()){
        //    if(star.top()>open.top()){
        //     star.pop();
        //     open.pop();
        //    }else{
        //     return false;
        //    }
        // }
        // return open.empty();
    }
};
