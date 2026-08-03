class Solution {
public:
    void dfs(
        vector<int> &els,
        vector<bool> &used,
        vector<vector<int>> &ans,
        vector<int> &cand
        ){
            if(cand.size()==els.size()){
                ans.push_back(cand);
                return;
            }

            for(int i=0;i<els.size();i++){
                if(used[i]){
                    continue;
                }
                int el = els[i];
                cand.push_back(el);
                used[i]=true;
                dfs(els,used,ans,cand);
                cand.pop_back();
                used[i]=false;
            }
        }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cand;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<bool> used(n,false);
        dfs(nums,used,ans,cand);
        return ans;
    }
};
