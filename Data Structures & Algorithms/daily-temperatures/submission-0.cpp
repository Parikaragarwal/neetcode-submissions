class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& ta) {
        vector<int> ans(ta.size(),0);

        for(int i=0;i<ta.size()-1;i++){
            int cand=0;
            for(int j=i+1;j<ta.size();j++){
                if(ta[j]>ta[i]){
                    ans[i]=j-i;
                    break;
                }
            }
        }
        return ans;
    }
};
