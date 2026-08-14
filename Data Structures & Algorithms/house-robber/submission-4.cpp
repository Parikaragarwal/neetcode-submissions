class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        // if(n==3){
        //     return max(nums[2]+nums[0],nums[1]);
        // }
        nums[1] =max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            nums[i]=max(nums[i-1],nums[i-2]+nums[i]);
        }
        return max(nums[n-1],nums[n-2]);
    }
};
