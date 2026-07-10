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
        unordered_set<int> elements(nums.begin(),nums.end());
        int ans = 0;
        for(int el:nums){
          int chainln = 1;
          int chainel = el;
          while(elements.contains(chainel+1)){
            chainln++;
            chainel++;
          }
          ans = max(ans,chainln);
        }
        return ans;


    }
};
