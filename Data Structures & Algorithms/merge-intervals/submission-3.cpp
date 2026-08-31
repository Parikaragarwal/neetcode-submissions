class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1){
            return intervals;
        }

        vector<vector<int>> ans;
        int m = 0;
        for(int i=0;i<n;i++){
            m = max(m,intervals[i][0]);
        }
        vector<int> mp(m+1,-1);
        for(int i=0;i<n;i++){
            mp[intervals[i][0]]=max(mp[intervals[i][0]],intervals[i][1]+1);
        }
        int start=-1;
        int end=-1;
        for(int i=0;i<=m;i++){

            if(i==end){
                ans.push_back({start,end-1});
                start=-1;
                end=-1;
            }

            if(start==-1 && mp[i]!=-1){
                start=i;
                end = mp[i];
            }else if(start!=-1 && mp[i]!=-1){
                end = max(end,mp[i]);
            }
            
        }
        if(start!=-1){
            ans.push_back({start,end-1});
        }
        return ans;

        // sort(intervals.begin(),intervals.end());
        // vector<vector<int>> ans;
        // ans.push_back(intervals[0]);
        // for(int i=1;i<n;i++){
        //     int an = ans.size();
        //     if(ans[an-1][1]>=intervals[i][0]){
        //         ans[an-1][1]=max(ans[an-1][1],intervals[i][1]);
        //     }else{
        //         ans.push_back(intervals[i]);
        //     }
        // }
        // return ans;
    }
};
