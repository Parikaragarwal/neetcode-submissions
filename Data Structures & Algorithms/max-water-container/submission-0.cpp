class Solution {
public:
    int maxArea(vector<int>& heights) {
        int size = heights.size();
        int ans = 0;
        for(int i=0;i<size-1;i++){
          for(int j=i+1;j<size;j++){
            int wall  = min(heights[i],heights[j]);
            ans = max(ans,(j-i)*wall);
          }
        }
        return ans;
    }
};
