class Solution {
private:
long long hash(int a, int b) {
    return (static_cast<long long>(a) << 32) |
           static_cast<unsigned int>(b);
}
public:
    int comb(
        vector<int> &nums,
        int sum,
        int target,
        int id,
        unordered_map<long long,int> &dp
    ){
        int n = nums.size();
        if(id==n){
            return (int)sum==target;
        }
        long long hsh = hash(id,sum);
        if(dp.contains(hsh)){
            return dp[hsh];
        }
        return dp[hsh]=(
            comb(nums,sum-nums[id],target,id+1,dp)
            +
            comb(nums,sum+nums[id],target,id+1,dp)
            );
    }

    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>sum || (sum-target)%2!=0){
            return 0;
        }

        int pos = (sum+target)/2;
        target = pos;
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[n][0]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=target;j++){
                int prev = (j-nums[i])>=0?dp[i+1][j-nums[i]]:0;
                dp[i][j]=dp[i+1][j]+prev;
            }
        }
        return dp[0][target];
        // int totalstates = totalsum*2;
        // unordered_map<long long,int> dp;
        // return comb(nums,0,target,0,dp);
    }
};
