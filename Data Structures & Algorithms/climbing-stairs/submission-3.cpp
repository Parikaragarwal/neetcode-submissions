class Solution {
private:
unordered_map<int,int> dp;
public:
    Solution(){
      dp[0]=1;
      dp[1]=1;
      dp[2]=2;
      dp[3]=3;
    }
    int climbStairs(int n) {

        vector<int> ans(n+2,0);
        ans[0]=1;
        for(int i=0;i<n;i++){
          ans[i+1]+=ans[i];
          ans[i+2]+=ans[i];
        }
        return ans[n];
        // if(n<0){
        //   return 0;
        // }
        // if(dp[n]){
        //   return dp[n];
        // }

        // if(!dp.contains(n-1)){
        //   dp[n-1] = climbStairs(n-1);
        // }
        // if(!dp.contains(n-2)){
        //   dp[n-2] = climbStairs(n-2);
        // }

        // return dp[n-1]+dp[n-2];
    }
};
