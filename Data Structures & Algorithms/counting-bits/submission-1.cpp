class Solution {
public:
    int bitFloor(int n){
       int i = 0;
       while(n!=0){
        n=n>>1;
        i++;
       }
       return 1<<i;
    }
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> ans={0,1};
        for(int i=2;i<=n;i++){
            ans.push_back(1+ans[i-(i & (~i+1))]);
        }
        return ans;
    }
};
