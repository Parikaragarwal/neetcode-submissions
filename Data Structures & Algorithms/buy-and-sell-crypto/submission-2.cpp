class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();


        // int ans=0;
        // for(int i=0;i<size-1;i++){
        //     for(int j=i+1;j<size;j++){
        //        ans = max(ans,prices[j]-prices[i]);
        //     }
        // }
        // return ans;

        int ans=0;
        int rmx=0;
        int j = size;
        while(j--){
            ans = max(ans,(rmx-prices[j]));
            rmx=max(rmx,prices[j]);
        }
        return ans;

    }
};
