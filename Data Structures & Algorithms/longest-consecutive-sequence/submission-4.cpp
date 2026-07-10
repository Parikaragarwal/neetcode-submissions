class Solution {
public:
    //  bool checkExists(vector<int> &nums,int target){
    //   for(int el:nums){
    //     if(el==target){
    //       return true;
    //     }
    //   }
    //   return false;
    // }

    int findChain(unordered_map<int,int> &chain,
    unordered_set<int> &s
    ,int n){
      if(chain.contains(n)){
        return chain[n];
      }
      if(!s.contains(n-1)){
        chain[n]=1;
        return 1;
      }
      chain[n] = findChain(chain,s,n-1)+1;
      return chain[n];
    }

    int longestConsecutive(vector<int>& nums) {

        // unordered_set<int> elements(nums.begin(),nums.end());
        // int ans = 0;
        // for(int el:nums){
        //   int chainln = 1;
        //   int chainel = el;
        //   while(elements.contains(chainel+1)){
        //     chainln++;
        //     chainel++;
        //   }
        //   ans = max(ans,chainln);
        // }
        // return ans;

        // set<int> sorter(nums.begin(),nums.end());
        // vector<int> arr(sorter.begin(),sorter.end());
        // int ans=0;
        // for(int i=0;i<arr.size();i++){
        //   int chainel = arr[i];
        //   int chainln = 1;
        //   while(i<arr.size()-1 && arr[i+1]==arr[i]+1 ){
        //     chainln++;
        //     i++;
        //   }
        //   ans= max(ans,chainln);
        // }
        // return ans;

        // unordered_map<int,int> chain;
        // unordered_set<int> s(nums.begin(),nums.end());
        // int ans=0;
        // for(int el:s){         
        //   ans= max(ans,findChain(chain,s,el));
        // }
        // return ans;

        unordered_set<int> elements(nums.begin(),nums.end());
        int ans = 0;
        for(int el:nums){
          int chainln = 1;
          int chainel = el;
          if(elements.contains(el+1) && !elements.contains(el-1)){
          while(elements.contains(chainel+1)){
            chainln++;
            chainel++;
          }
          }
          ans = max(ans,chainln);
        }
        return ans;

    }
};
