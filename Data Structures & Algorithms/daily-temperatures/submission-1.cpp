class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& ta) {
        vector<int> ans(ta.size(),0);

        // for(int i=0;i<ta.size()-1;i++){
        //     int cand=0;
        //     for(int j=i+1;j<ta.size();j++){
        //         if(ta[j]>ta[i]){
        //             ans[i]=j-i;
        //             break;
        //         }
        //     }
        // }




        stack<int> s;
        for(int i=0;i<ta.size();i++){
            while(!s.empty() && ta[s.top()]<ta[i]){
                ans[s.top()] = i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};
