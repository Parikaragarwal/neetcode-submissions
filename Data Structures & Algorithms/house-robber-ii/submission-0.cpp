class Solution {
public:
    int robo(vector<int> &nums,int start,int end){
        int n = end-start+1;
        if(n==1){
            return nums[start];
        }
        if(n==2){
            return max(nums[start+1],nums[start]);
        }

        int prev1 = nums[start];
        int prev2 = max(nums[start],nums[start+1]);
        int curr;
        for(int i=start+2;i<=end;i++){
            curr = max(prev1+nums[i],prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        return curr;

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[1],nums[0]);
        }
        return max(robo(nums,1,n-1),robo(nums,0,n-2));
    }
};
