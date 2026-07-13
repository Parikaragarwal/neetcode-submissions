class Solution {
public: 
    int cti(char ch){
        return ch-'A';
    }
    int maxfeq(vector<int> &feq){
        int mx = INT_MIN;
        for(int el:feq){
            mx = max(mx,el);
        }
        return mx;
    }
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int size = s.size();
        int mxf = 0;
        vector<int> feq(26,0);
        int ans=0;
        

        while(r<size){
            int id = cti(s[r]);
            feq[id]++;
            mxf = maxfeq(feq);
            int win = r-l+1;
            while(win-mxf>k){
                feq[cti(s[l])]--;
                mxf=maxfeq(feq);
                l++;
                win= r-l+1;
            }
            ans = max(ans,win);
            r++;
        }
        return ans;
    }
};
