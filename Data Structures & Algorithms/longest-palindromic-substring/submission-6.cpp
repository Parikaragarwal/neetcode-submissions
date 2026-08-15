class Solution {
private:
unordered_map<long long,bool> cp;
long long hash(int a,int b){
    long long ans = 0;
    ans = ans | a;
    ans = ans <<32;
    ans = ans | b;
    return ans;
}
bool checkpalindrome(string &s,int start,int end){
    long long hsh = hash(start,end);
    if(cp.contains(hsh)){
        return cp[hsh];
    }

    while(start<=end && s[start]==s[end]){
        start++;
        end--;
    }
    if(start>end){
        return cp[hsh]=true;
    }else{
        return cp[hsh]=false;
    }
}
public:
    string recursion(string &s,int start,int end
    ,unordered_map<long long,string> &dp){
        if(end<start){
            return "";
        }
        long long hsh = hash(start,end);
        if(dp.contains(hsh)){
            return dp[hsh];
        }
        int a = start;
        int b = end;
        if(checkpalindrome(s,start,end)){
            return dp[hsh] = s.substr(a,b-a+1);
        }
        
        string cand1 = recursion(s,start+1,end,dp);
        string cand2 = recursion(s,start,end-1,dp);
        return dp[hsh] = cand1.size()>cand2.size()?cand1:cand2;
    }

    void expand(string &s,int l,int r, string &ans){
        int size = 0;
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            size=r-l+1;
            l--;
            r++;
        }
        if(size>ans.size()){
            ans = s.substr(l+1,size);
        }
    }
    string longestPalindrome(string s) {
        if(s.size()==1){
            return s;
        }
        // unordered_map<long long,string> dp;
        // int n = s.size();
        // return recursion(s,0,n-1,dp);
        int n = s.size();
        string ans = "";
        for(int i=0;i<n-1;i++){
            expand(s,i,i,ans);
            if(s[i]==s[i+1])
            expand(s,i,i+1,ans);
        }
        return ans;
    }
};
