class Solution {
private:
    int coins(
        vector<int> &nums,
        int start,
        int end,
        vector<vector<int>> &dp
        // unordered_map<long long,int> &dp
    ){
        int n = nums.size();
        if(start<0 || end>=n || start>end){
            return 0;
        }
        int l = start-1<0?1:nums[start-1];
        int r = end+1>=n?1:nums[end+1];
        if(end==start){
            return nums[end]*l*r;
        }
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        
        int ans = 0;
        for(int i=start;i<=end;i++){
            int val = nums[i]*l*r;
            int bmax = val+(
                coins(nums,i+1,end,dp)+
                coins(nums,start,i-1,dp)
            );
            
            ans = max(ans,bmax);
        }
        return dp[start][end]=ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<long long,int> dp;

        // vector<vector<int>> dp(n,vector<int>(n,-1));
        // return coins(nums,0,n-1,dp);
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            int start = 0;
            int end = i;
            while(end<n){
                int ans=0;
                int l = start-1<0?1:nums[start-1];
                int r = end+1>=n?1:nums[end+1];
                
                for(int j=start;j<=end;j++){
                    int val = l*r*nums[j];
                    int a = j-1>=0?dp[start][j-1]:0;
                    int b = j+1<n?dp[j+1][end]:0;
                    int bmax = val+(a+b);
                    ans = max(ans,bmax);
                }
                dp[start][end]=ans;
                start++;
                end++;
            }
        }
        return dp[0][n-1];
    }
};
