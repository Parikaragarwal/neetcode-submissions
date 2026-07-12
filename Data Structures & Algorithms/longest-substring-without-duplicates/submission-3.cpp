class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size = s.size();

        // unordered_set<char> seen;
        // if(size<2){
        //     return size;
        // }
        // int l = 0;
        // int r = l+1;
        // int win=1;
        // int ans = 0;
        // seen.insert(s[0]);

        // while(r<size){
        //     while(l<r && seen.contains(s[r])){
        //         win--;
        //         seen.erase(s[l]);
        //         l++;
        //     }
        //     seen.insert(s[r]);
        //     win++;
        //     ans = max(ans,win);
        //     r++;
        // }
        
        // return ans;


        if(size<2){
            return size;
        }
        unordered_map<char,int> seen;
        
        int l=0;
        int r=l;
        int ans = 0;
        while(r<size){

            if(seen.contains(s[r])){
            l = max(l,seen[s[r]]+1);
            }
             seen[s[r]]=r;  
             ans = max(ans,r-l+1);
             r++;
            
        }
        return ans;


    }
};
