class Solution {
public:
    void backtrack(
        int openable,
        int closable,
        string s,
        vector<string> &ans
    ){
        if(!openable){
            while(closable--){
                s.push_back(')');
            }
            ans.push_back(s);
            return;
        }

        for(int i=0;i<=closable;i++){
            // int k=0;
            // for(k=1;k<=i;k++){
            //     s.push_back(')');
            // }
            s.push_back('(');
            backtrack(openable-1,closable-i+1,s,ans);
            s.pop_back();
            s.push_back(')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(n,0,"",ans);
        return ans;
    }
};
