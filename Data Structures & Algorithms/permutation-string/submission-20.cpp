class Solution {
public:
    int cti(char ch){
        return ch-'a';
    }
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()){
            return false;
        }
        vector<int> crs(26,0);
        for(char c:s1){
            crs[cti(c)]++;
        }
        
        for(int i=0;i<s2.size();i++){
            if(crs[cti(s2[i])]){
                int l = i;
                int r = i;
                vector<int> fc(26,0);
                while(r<s2.size() && r<l+s1.size()){
                    int el = s2[r]-'a';
                    if(crs[el] && fc[el]<crs[el]){
                        fc[el]++;
                    }else if(crs[el]==0){
                        i=r;
                        break;
                    }else{
                        while(l<=r && fc[el]==crs[el]){
                           
                            fc[cti(s2[l])]--;
                            l++;
                        }
                        fc[el]++;
                        i=r;
                    }
                r++;
                }
                if(crs==fc){
                    return true;
                }
            }
        }

        return false;
    }
};
