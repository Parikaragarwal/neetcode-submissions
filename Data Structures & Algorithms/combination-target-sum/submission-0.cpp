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
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> cand;
        backtrack(nums,ans,0,target,0,cand);
        return ans;
    }
};
