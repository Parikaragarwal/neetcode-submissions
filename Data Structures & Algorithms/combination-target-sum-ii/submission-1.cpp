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
        backtrack(nums,cand,ans,target,i+1);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> cand;

        backtrack(candidates,cand,ans,target,0);
        return ans;
    }
};
