class Solution {
public:
    bool checkpalindrome(const string &s){
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool checkvalid(vector<string> &comb){
       bool ans=true;
        for(const string &el:comb){
            ans = ans & checkpalindrome(el);
            if(!ans){
                return false;
            }
        }
        return ans;
    }
    void backtrack(
        string s,
        int start,
        string cand,
        vector<string> &comb,
        vector<vector<string>> &ans
    ){
        if(start==s.size()-1){
            cand.push_back(s[start]);
            comb.push_back(cand);
            if(checkvalid(comb)){
                ans.push_back(comb);
            }
            comb.pop_back();
            return;
        }
        cand.push_back(s[start]);
        comb.push_back(cand);
        backtrack(s,start+1,"",comb,ans);
        comb.pop_back();
        backtrack(s,start+1,cand,comb,ans);
    }
    vector<vector<string>> partition(string s) {
       vector<string> comb;
       vector<vector<string>> ans;
       backtrack(s,0,"",comb,ans);
       return ans;
    }
};
