class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int size = s.size();
        if(size<2){
            return size;
        }
        int l = 0;
        int r = l+1;
        int win=1;
        int ans = 0;
        seen.insert(s[0]);

        while(r<size){
            while(l<r && seen.contains(s[r])){
                win--;
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[r]);
            win++;
            ans = max(ans,win);
            r++;
        }
        
        return ans;
    }
};
