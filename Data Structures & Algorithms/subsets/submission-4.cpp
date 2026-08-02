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
    void dfs(
       vector<int> &nums,
        vector<vector<int>> &ans,
        vector<int> &cand,
        int id 
    ){
       
        ans.push_back(cand);
            
        
        for(int i=id;i<nums.size();i++)
        {
            cand.push_back(nums[i]);
            dfs(nums,ans,cand,i+1);
            cand.pop_back();
        }
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        // vector<int> cand;
        // backtrack(nums,ans,cand,0);
        // return ans;


        // int n = (1<<((int)nums.size()));
        // for(int i=0;i<n;i++){
        //     vector<int> cand;
        //     for(int j=0;j<(int)nums.size();j++){
        //         if((i>>j)&1){
        //             cand.push_back(nums[j]);
        //         }
        //     }
        //     ans.push_back(cand);
        // }
        // return ans;

        // ans={{}};
        // for(int num:nums){
        //     int size = ans.size();
        //     for(int i=0;i<size;i++){
        //         vector<int> cand = ans[i];
        //         cand.push_back(num);
        //         ans.push_back(cand);
        //     }
        // }
        // return ans;

        vector<int> cand;
        dfs(nums,ans,cand,0);
        return ans;

    }
};