class Solution {
public:
    bool checkalnu(char ch){
       return (ch>='A' & ch<='Z') || (ch>='0' & ch<='9') || (ch>='a' & ch<='z');
    }
    bool isPalindrome(string s) {   
      int n = s.size();
      int i=0;
      int j=n-1;

      int mid = (n-1)/2;

      while(i<=j){
        if(!checkalnu(s[i])){
          i++;
          continue;
        }
        if(!checkalnu(s[j])){
          j--;
          continue;
        }

        if(tolower(s[i++])!=tolower(s[j--])){
          return false;
        }
      }
      return true;
    }
};
