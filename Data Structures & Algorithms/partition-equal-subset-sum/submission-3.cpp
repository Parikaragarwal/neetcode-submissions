class Solution {
private:
    bool possible(
        vector<int> &nums,
        int sum,
        int id,
        vector<vector<int>> &dp
    ){
        int n = nums.size();
        if(id==n || sum<0){
            return false;
        }
        if(sum==0){
            return true;
        }
        if(dp[id][sum]!=-1){
            return (bool)dp[id][sum];
        }
        return dp[id][sum]=(possible(nums,sum-nums[id],id+1,dp) || possible(nums,sum,id+1,dp));
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        int target = sum/2;
        return possible(nums,target,0,dp);
    }
};
