class Solution {
public:
    string countToString(int count) {
    string s = to_string(count);
    while (s.size() < 3)
        s = "0" + s;
    return s;
   }


    string formatString(string s){
      return "#"+ countToString(s.size()) +"#"+s;
    }


    string encode(vector<string>& strs) {
      string encoded = "";
      for(string str:strs){
        encoded.append(formatString(str));
      }
      return encoded;
    }

    vector<string> decode(string s) {
      vector<string> ans={};
      int i=0;
      while(i<s.size()){
        int count = stoi(s.substr(i+1,3));
        i+=4;
        string member = s.substr(i+1,count);
        ans.push_back(member);
        i+=count+1;
      }
      return ans;
    }
};