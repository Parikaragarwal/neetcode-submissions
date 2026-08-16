class Solution {
public:
    void expand(string &s,int l,int r,int &ans){
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            ans++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        int n = s.size();
        if(n==1){
            return 1;
        }
    

        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     expand(s,i,i,ans);
        //     if(i+1<n && s[i]==s[i+1])
        //     expand(s,i,i+1,ans);
        // }
        // return ans;

        vector<vector<bool>> dp(n,vector<bool>(n));
        int ans = 0;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
            ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                int start = j;
                int end = j+i;
                if(s[start]!=s[end] || 
                (start+1<=end-1 && !dp[start+1][end-1] ) ){
                    dp[start][end]=false;
                    continue;
                }
                dp[start][end]=true;
                ans++;
            }
        }
        return ans-n;
    }
};
