class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int sum=0;
        bool allneg = true;
        int negans = nums[0];
        for(int x:nums){
            if(x>=0){
                allneg=false;
            }
            negans = max(negans,x);
            if(sum+x<0){
                sum=0;
            }else{
                sum+=x;
            }
            ans = max(ans,sum);
        }
        return allneg?negans:ans;
    }
};
