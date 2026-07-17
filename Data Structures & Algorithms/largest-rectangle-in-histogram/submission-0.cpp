class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int ans = 0;
        for(int el:h){
            ans = max(el,ans);
        }


        int n = h.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int mn = INT_MAX;
                for(int k=i;k<=j;k++){
                    mn = min(mn,h[k]);
                }
                ans = max(ans,(j-i+1)*mn);
            }
        }
        return ans;
    }
};
