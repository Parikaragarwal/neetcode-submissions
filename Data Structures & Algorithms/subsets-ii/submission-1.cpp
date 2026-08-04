class Solution {
public:
    void backtrack(
        vector<int> &nums,
        vector<vector<int>> &ans,
        vector<int> &cand,
        int id
    ){
        if(id==nums.size()){
            ans.push_back(cand);
            return;
        }

        cand.push_back(nums[id]);
        backtrack(nums,ans,cand,id+1);
        cand.pop_back();
        while(id+1<nums.size() && nums[id+1]==nums[id]){
            id++;
        }
        backtrack(nums,ans,cand,id+1);
    }

    void looptrack(
        vector<int> &nums,
        vector<vector<int>> &ans,
        vector<int> &cand,
        int id
    ){
        ans.push_back(cand);
            
        for(int i=id;i<nums.size();i++){
            if(i>id && nums[i]==nums[i-1]){
                continue;
            }
            cand.push_back(nums[i]);
            looptrack(nums,ans,cand,i+1);
            cand.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> cand;
        // backtrack(nums,ans,cand,0);
        looptrack(nums,ans,cand,0);
        return ans;
    }
};
