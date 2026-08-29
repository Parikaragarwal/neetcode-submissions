class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1e9);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            int ans = INT_MAX;
            for(int j=i+1;j<=min(n-1,i+nums[i]);j++){
                ans = min(ans,dp[j]);
            }
            dp[i]=ans<INT_MAX?ans:1e9;
            dp[i]++;
        }
        return dp[0];
    }
};
