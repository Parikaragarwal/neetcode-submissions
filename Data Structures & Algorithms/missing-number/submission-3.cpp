class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        n = n*(n+1)/2;
        for(int x:nums){
            n-=x;
        }
        return n;
        int xr=n;
        for(int i=0;i<n;i++){
            xr = xr^i;
            xr = xr^(nums[i]);
        }
        return xr;
        return n;
    }
};
