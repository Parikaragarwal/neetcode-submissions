class Solution {
public:
    bool checkalnu(char ch){
      if(ch-'0'>=0 && ch-'0'<=9){
        return true;
      }
      int el = (int)ch;

      if(el>=65 && el<=(65+26)){
        return true;
      }
      if(el>=97 && el<=(97+26)){
        return true;
      }

      return false;
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
