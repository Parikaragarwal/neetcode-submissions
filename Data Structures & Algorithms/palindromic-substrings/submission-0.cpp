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
        int ans = 0;
        for(int i=0;i<n;i++){
            expand(s,i,i,ans);
            if(i+1<n && s[i]==s[i+1])
            expand(s,i,i+1,ans);
        }
        return ans;
    }
};
