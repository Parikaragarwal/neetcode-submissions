class Solution {
public:
    void backtrack(
        vector<int> &nums,
        vector<int> &cand,
        vector<vector<int>> &ans,
        int target,
        int id
    ){
        if(!target){
            ans.push_back(cand);
            return;
        }
        if(id==nums.size() || target<0){
            return;
        }

        cand.push_back(nums[id]);
        backtrack(nums,cand,ans,target-nums[id],id+1);
        cand.pop_back();
        int i=id;
        while(i<nums.size()-1 && nums[i+1]==nums[i]){i++;}
        // if(id<nums.size()-1 && nums[i+1]!=nums[i])
        backtrack(nums,cand,ans,target,i+1);
        
    }

    void dfs(
        vector<int> &nums,
        vector<vector<int>> &ans,
        int id,
        int target,
        vector<int> &cand 
    ){
        if(target<=0){
            if(!target)
            ans.push_back(cand);
            return;
        }
        
        for(int i=id;i<nums.size();i++){
            cand.push_back(nums[i]);
            dfs(nums,ans,i+1,target-nums[i],cand);
            while(i+1<nums.size() && nums[i]==nums[i+1]){
                i++;
            }
            cand.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> cand;
        dfs(candidates,ans,0,target,cand);
        // backtrack(candidates,cand,ans,target,0);
        return ans;
    }
};
