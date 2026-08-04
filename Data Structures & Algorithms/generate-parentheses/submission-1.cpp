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
        // vector<string> ans;
        // string s="";
        // backtrack(n,0,s,ans);
        // return ans;

        vector<vector<string>> dp(n+1);
        dp[0]={""};

        for(int j=1;j<=n;j++){
            for(int i=0;i<j;i++){
                int left = i;
                int right = j-1-i;
                for(const string &l:dp[left]){
                    for(const string &r:dp[right]){
                        string cand = "("+l+")"+r;
                        dp[j].push_back(cand);
                    }
                }
            }
        }
        return dp[n];
    }
};
