class Solution {
public:
    void backtrack(
        vector<int> &nums,
        vector<vector<int>> &ans,
        int id,
        int target,
        int sum,
        vector<int> &cand
        ){
            if(sum==target){
                ans.push_back(cand);
                return;
            }
            if(id==nums.size() || target<sum){
                return;
            }

            cand.push_back(nums[id]);
            backtrack(nums,ans,id,target,sum+nums[id],cand);
            cand.pop_back();
            backtrack(nums,ans,id+1,target,sum,cand);
        }
    void dfs(
        vector<int> &nums,
        vector<vector<int>> &ans,
        int id,
        int target,
        vector<int> &cand 
    ){
        for(int i=id;i<nums.size();i++){
            if(target<=0){
                if(target==0)
                ans.push_back(cand);
                return;
            }
            cand.push_back(nums[i]);
            dfs(nums,ans,i,target-nums[i],cand);
            cand.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> cand;
        // backtrack(nums,ans,0,target,0,cand);
        sort(nums.begin(),nums.end());
        dfs(nums,ans,0,target,cand);
        return ans;
    }
};
