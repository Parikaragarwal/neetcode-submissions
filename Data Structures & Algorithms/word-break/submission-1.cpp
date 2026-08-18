class Solution {
private:
    int wc;
    bool possible(
        string s,
        unordered_set<string> &dict,
        int start,
        int takechars,
        vector<vector<int>> &dp
    ){
        int n = s.size();
        if(start==n){
            return true;
        }

        if(takechars>wc || start+takechars>n){
            return false;
        }

        if(dp[start][takechars]!=-1){
            return dp[start][takechars];
        }
        string subs = s.substr(start,takechars);
        if(dict.count(subs) && possible(s,dict,start+takechars,1,dp)){
           return dp[start][takechars]=(int)true;
        }
        return dp[start][takechars]=(int)possible(s,dict,start,takechars+1,dp);
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        int n = s.size();
        int mxword=0;
        for(const string &s:wordDict){
            dict.insert(s);
            mxword = max(mxword,(int)s.size());
        }
        wc=mxword;
        vector<vector<int>> dp(n,vector<int>(wc+1,-1));
        return possible(s,dict,0,1,dp);
    }
};
