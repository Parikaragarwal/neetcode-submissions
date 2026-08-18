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

        // vector<vector<int>> dp(n,vector<int>(wc+1,-1));
        // return possible(s,dict,0,1,dp);


        // vector<bool> dp(n,false);
        // if(dict.count(s)){
        //     return true;
        // }
        // // bool flag = true;
        // // for(int i=0;i<n;i++){
        // //     if(dp[i]==true || (i==0 && flag )){
        // //         int j = dp[i]?i+1:i;
        // //         int boundary = min(n,j+wc);
        // //         string can="";
        // //         while(j<boundary){
        // //             can.push_back(s[j]);
        // //             if(dict.count(can)){
        // //                 dp[j]=true;
        // //             }
        // //             j++;
        // //         }
        // //         if(i==0 && flag){
        // //             i--;
        // //             flag=false;
        // //         }
        // //     }
        // // }
        // // return dp[n-1];

        queue<int> q;
        unordered_set<int> visited;
        q.push(-1);
        while(!q.empty()){
            int id = q.front()+1;
            visited.insert(id-1);
            q.pop();
            if(id==n){
                return true;
            }
            string cand = "";
            int boundary = min(n,id+wc);
            for(int i=id;i<boundary;i++){
                cand.push_back(s[i]);
                if(dict.count(cand) && !visited.count(i)){
                    visited.insert(i);
                    q.push(i);
                }
            }
        }
        return false;
    }
};
