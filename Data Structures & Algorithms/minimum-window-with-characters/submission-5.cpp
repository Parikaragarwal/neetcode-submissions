class Solution {
public:
    string minWindow(string s, string t){
        if(t=="" || t.size()>s.size()){
            return "";
        }
        if(s==t){
            return t;
        }

        unordered_map<char,int> tfc;
        unordered_map<char,int> sfc;

        for(char c:t){
            tfc[c]++;
        }

        int l=0;
        int match = 0;
        string ans = "";
        for(int r=0;r<s.size();r++){
            if(tfc.contains(s[r])){
                sfc[s[r]]++;
                if(sfc[s[r]] == tfc[s[r]]){
                    match++;
                }
            }
            while(l<=r && match==tfc.size()){
                if(ans=="" || r-l+1<ans.size()){
                    ans = s.substr(l,r-l+1);
                }
                
                if(sfc.contains(s[l]) && sfc[s[l]]>0){
                    if(--sfc[s[l]]+1==tfc[s[l]]){
                        match--;
                    }
                }
                l++;            }
        }
        return ans;
    }
};
