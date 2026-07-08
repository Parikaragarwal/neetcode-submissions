class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.length()!=t.length()){
        return false;
      }
    
    // for(int i=0;i<s.length();i++){
    //     bool found  = false;
    //     for(int j=0;j<t.length();j++){
    //         if(s[i]==t[j]){
    //             t[j]='X';
    //             found = true;
    //             break;            }
    //     }
    //     if(!found){
    //         return false;
    //     }
    // }

    // return true;
    
    
    //  sort(s.begin(),s.end());
    //  sort(t.begin(),t.end());
    //  return s==t;

    unordered_map<char,int> frequency;
    for(char el:s){
        frequency[el]++;
    }

    for(char el:t){
        if(!frequency.contains(el) || frequency[el]==0){
            return false;
        }
        frequency[el]--;
    }
    return true;
    }
};
