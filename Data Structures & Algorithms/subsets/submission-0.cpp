class Solution {
public:
    void backtrack(
        vector<int> &nums,
        vector<vector<int>> &ans,
        vector<int> &cand
        ,int id){
        if(id==nums.size()){
            ans.push_back(cand);
            return;
        }

        cand.push_back(nums[id]);
        backtrack(nums,ans,cand,id+1);
        cand.pop_back();
        backtrack(nums,ans,cand,id+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cand;
        backtrack(nums,ans,cand,0);
        return ans;
    }
};