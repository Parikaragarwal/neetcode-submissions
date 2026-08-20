class Solution {
private:
    bool possible(
        vector<int> &nums,
        int sum,
        int id,
        vector<vector<int>> &dp
    ){
        int n = nums.size();

        if(sum==0){
            return true;
        }
        if(id==n-1){
            return nums[id]==sum;
        }
        if(sum<0){
            return false;
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
        int target = sum/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                bool taken = false;
                bool forgo = false;
                if(i+1<n){
                    forgo = dp[i+1][j];
                    if(j-nums[i]>=0){
                        if(j-nums[i]==0){
                            taken=true;
                        }else{
                            taken = dp[i+1][j-nums[i]];  
                        }
                    }
                }
                dp[i][j]=taken || forgo;
            }
        }
        return dp[0][target];

        // vector<vector<int>> dp(n,vector<int>(target+1,-1));
        // // return possible(nums,target,0,dp);
    }
};
