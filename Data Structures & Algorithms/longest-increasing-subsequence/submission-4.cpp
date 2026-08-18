class Solution {
public:
    int longest(
        vector<int> &nums,
        int id,
        int curr
    ){
        int n = nums.size();
        if(id==n){
            return 0;
        }
        int a = INT_MIN;
        if(nums[id]>curr){
            a = 1+longest(nums,id+1,nums[id]);
        }
        int b = longest(nums,id+1,curr);
        return max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int final = 1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            int ans = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    ans=max(ans,dp[j]);
                }
            }
            dp[i]+=ans;
            final = max(final,dp[i]);
        }
        return final;
        //  return longest(nums,0,INT_MIN);
    }
};
