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
        // int finalans = 1;
        // vector<int> dp(n,1);
  
        vector<int> tail;
        tail.push_back(INT_MIN);

        for(int curr:nums){

            int start = 0;
            int end = tail.size()-1;
            while(start<=end){
                int mid = start+(end-start)/2;
                if(tail[mid]<curr){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
            if(end==tail.size()-1){
                tail.push_back(curr);
            }else{
                tail[end+1]=min(tail[end+1],curr);
            }

            // // for(int j=0;j<i;j++){
            // //     if(nums[j]<nums[i]){
            // //         ans=max(ans,dp[j]);
            // //     }
            // // }
            // dp[i]+=ans;
            // finalans = max(finalans,dp[i]);
        }

        return tail.size()-1;
        // return finalans;


        //  return longest(nums,0,INT_MIN);
    }
};
