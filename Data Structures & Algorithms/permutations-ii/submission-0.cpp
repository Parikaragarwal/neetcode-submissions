class Solution {
public:
// void swaptrack(
//         vector<int> &nums,
//         vector<vector<int>> &ans,
//         int id
//     ){
//         if(id==nums.size()){
//             ans.push_back(nums);
//             return;
//         }

//         for(int i=id;i<nums.size();i++){
//                 while(i+1<nums.size() && nums[i+1]==nums[id]){
//                     i++;
//                 }
//             swap(nums[id],nums[i]);
//             swaptrack(nums,ans,id+1);
//             swap(nums[id],nums[i]);
//         }
//     }
    void backtrack(
        unordered_map<int,int> &f,
        vector<int> &cand,
        vector<vector<int>> &ans,
        int size
    ){
        if(size==cand.size()){
            ans.push_back(cand);
            return;
        }
        for(auto it:f){
            if(it.second==0){
                continue;
            }
            int el = it.first;
            cand.push_back(el);
            f[el]--;
            backtrack(f,cand,ans,size);
            cand.pop_back();
            f[el]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cand;
        unordered_map<int,int> f;
        for(int el:nums){
            f[el]++;
        }
        int size=nums.size();
        backtrack(f,cand,ans,size);
        return ans;
        // sort(nums.begin(),nums.end());
        // swaptrack(nums,ans,0);
        // return ans;
    }
};