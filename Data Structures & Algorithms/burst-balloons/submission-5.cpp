class Solution {
private:
vector<vector<int>> dp;
long long hash(int a,int b,int c,int d){
    long long ans = 0;
    vector<int> els = {a,b,c,d};
    for(int i=0;i<3;i++){
        ans = ans | els[i];
        ans = ans << 16;
    }
    ans = ans | els[3];
    return ans;
}
public:
    int coins(
        vector<int> &nums,
        int start,
        int end,
        int l,
        int r,
        unordered_map<long long,int> &dp
    ){
        int n = nums.size();
        if(start<0 || end>=n || start>end){
            return 0;
        }
        if(end==start){
            return nums[end]*l*r;
        }
        long long hsh = hash(start,end,l,r);
        if(dp.contains(hsh)){
            return dp[hsh];
        }
        int ans = 0;
        for(int i=start;i<=end;i++){
            int val = nums[i]*l*r;
            int bmax = val+(
                coins(nums,i+1,end,nums[i],r,dp)+
                coins(nums,start,i-1,l,nums[i],dp)
            );
            
            ans = max(ans,bmax);
        }
        return dp[hsh]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        unordered_map<long long,int> dp;
        return coins(nums,0,n-1,1,1,dp);
    }
};
