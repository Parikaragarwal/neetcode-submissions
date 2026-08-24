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
        unordered_map<long long,int> dp;
        return comb(nums,0,target,0,dp);
    }
};
