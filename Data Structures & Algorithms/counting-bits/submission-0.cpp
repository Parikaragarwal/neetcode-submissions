class Solution {
public:
    int bitFloor(int n){
        return  n & (~n + 1);
    }
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> ans={0,1};
        for(int i=2;i<=n;i++){
            ans.push_back(1+ans[i-bitFloor(i)]);
        }
        return ans;
    }
};
