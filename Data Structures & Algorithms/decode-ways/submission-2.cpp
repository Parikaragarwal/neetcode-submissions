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
    bool isvalid(string &s,int id,int checkcount){
        if(id<0){
            return false;
        }
        if(s[id]=='0'){
            return 0;
        }
        int test = stoi(s.substr(id,checkcount));
        if(checkcount==1){
            return true;
            // if(test<=9 && test>=1){
            //     return true;
            // }else{
            //     return false;
            // }
        }else{
            if(test>=1 && test<=26){
                return true;
            }else{
                return false;
            }
        }
    }
    int numDecodings(string s) {
       int n = s.size();
    //    vector<int> dp(n+1,-1);
    //    return explore(s,0,dp);
    vector<int> dp(n+1,0);
    dp[n]=1;
    int next1=0;
    int next2=0;
    int curr = 1;
    for(int i=n;i>=1;i--){
        if(isvalid(s,i-1,1)){
            dp[i-1]+=dp[i];
        }
        if(isvalid(s,i-2,2)){
            dp[i-2]+=dp[i];
        }
    }
    return dp[0];
    }
};
