class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      
      int size = nums.size();



      // vector<int> inc(size+1);
      // vector<int> dec(size+1);
      // inc[0]=1;
      // dec[size]=1;
      // int prod = 1;

      // for(int i=1;i<size+1;i++){
      //   inc[i]=inc[i-1]*nums[i-1];
      // }

      // for(int i=size-1;i>=0;i--){
      //   dec[i] = dec[i+1]*nums[i];
      // }

      // vector<int> ans(size);
      // for(int i=0;i<size;i++){
      //   ans[i] = inc[i]*dec[i+1];
      // }
      // return ans;



      vector<int> ans(size);
      ans.push_back(1);
      int prod = 1;
      for(int i=size;i>=1;i--){
        ans[i-1]=ans[i]*nums[i-1];
      }
      for(int i=0;i<size;i++){
        ans[i]=prod*ans[i+1];
        prod*=nums[i];
      }
      ans.pop_back();
      return ans;

    }
};
