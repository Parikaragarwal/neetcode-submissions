class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int size = nums.size();

    //   for(int i=0;i<size-1;i++){
    //     for(int j=i+1;j<size;j++){
    //         if(nums[i]+nums[j]==target){
    //             return {i,j};
    //         }
    //     }
    //   }  
    //   return {-1,-1};

    unordered_map<int,vector<int>> idmap;
    for(int i=0;i<size;i++){
    idmap[nums[i]].push_back(i);    
    }

    if(target%2==0 && idmap.contains(target/2) && idmap[target/2].size()==2){
        return idmap[target/2];
    }

    for(int i=0;i<size;i++){
       int mapTarget = target-nums[i];
       if(idmap.contains(mapTarget)){
        if(i==idmap[mapTarget][0]){
            continue;
        }
        vector<int> ans = {i,idmap[mapTarget][0]};
        sort(ans.begin(),ans.end());
        return ans;
       }
    }
    return {-1,-1};
    }
};
