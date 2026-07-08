class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length()!=t.length()){
        return false;
      }
    
    for(int i=0;i<s.length();i++){
        bool found  = false;
        for(int j=0;j<t.length();j++){
            if(s[i]==t[j]){
                t[j]='X';
                found = true;
                break;            }
        }
        if(!found){
            return false;
        }
    }

    return true;
    
    
    //  sort(s.begin(),s.end());
    //  sort(t.begin(),t.end());
    //  return s==t;
    }
};
