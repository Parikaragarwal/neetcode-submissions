class Solution {
public:
    int explore(string &s,int start,vector<int> &dp){
        int ogstart = start;
        int n = s.size();
        if(start>=n){
            return 1;
        }
        if(dp[start]!=-1){
            return dp[start];
        }
        if(s[start]=='0'){
            return dp[start]=0;
        }
        int takeone = 0;
        int taketwo = 0;


        string el;

        el.push_back(s[start]);
        int to = stoi(el);

        if(to>0 && to<=9)
        takeone = explore(s,start+1,dp);

        start++;
        if(start==n){
            return dp[ogstart]=takeone;
        }

        el.push_back(s[start]);
        int tt = stoi(el);

        if(tt>=10 && tt<=26)
        taketwo = explore(s,start+1,dp);

        return dp[ogstart]=(takeone+taketwo);
    }
    int numDecodings(string s) {
       int n = s.size();
       vector<int> dp(n+1,-1);
       return explore(s,0,dp);
    }
};
