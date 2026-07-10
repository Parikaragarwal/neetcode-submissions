class Solution {
public:
     bool checkExists(vector<int> &nums,int target){
      for(int el:nums){
        if(el==target){
          return true;
        }
      }
      return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        for(int el:nums){
          int chainln = 1;
          int chainel = el;
          while(checkExists(nums,chainel+1)){
            chainln++;
            chainel++;
          }
          ans = max(ans,chainln);
        }
        return ans;
    }
};
