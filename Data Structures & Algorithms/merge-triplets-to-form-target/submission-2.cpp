class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> ans = {INT_MIN,INT_MIN,INT_MIN};
        for(auto triplet:triplets){
            bool skip = false;
            for(int i=0;i<3;i++){
                if(triplet[i]>target[i]){
                    // triplet={INT_MIN,INT_MIN,INT_MIN};
                    skip=true;
                    break;
                }
            }
            if(skip){
                continue;
            }
            for(int i=0;i<3;i++){
                ans[i]=max(ans[i],triplet[i]);
            }
        }
        return ans==target;
    }
};
