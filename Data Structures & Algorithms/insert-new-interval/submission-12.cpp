class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n = intervals.size();
      if(n==0){
        return {newInterval};
      }
      vector<vector<int>> ans;
      int a = newInterval[0];
      int b = newInterval[1];
      if(a<intervals[0][0] && b>intervals[n-1][1]){
        return {newInterval};
      }
      if(b<intervals[0][0]){
        ans.push_back(newInterval);
        for(auto &inv:intervals){
            ans.push_back(inv);
        }
        return ans;
      }
      if(a>intervals[n-1][1]){
        intervals.push_back(newInterval);
        return intervals;
      }

      int start = -1;
      int end = -1;
      for(int i=0;i<n;i++){
        int cs = intervals[i][0];
        int ce = intervals[i][1];
        if(a>=cs && a<=ce){
            start=i;
        }
        if(b>=cs && b<=ce){
            end = i;
        }
      }
      if(start == -1 && end == -1){
        bool flag = false;
        for(int i=0;i<n;i++){
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            if(cs>a && !flag){
                ans.push_back(newInterval);
                flag=false;
            }
            ans.push_back(intervals[i]);
        }
      }else if(start!=-1 && end!=-1){
        newInterval[0] = intervals[start][0];
        newInterval[1] = intervals[end][1];
        for(int i=0;i<n;i++){
            if(i==start){
                ans.push_back(newInterval);
                i=end;
            }else{
                ans.push_back(intervals[i]);
            }
        }
      }else{
        if(start!=-1){
            for(int i=0;i<n;i++){
                if(i==start){
                    intervals[start][1]=b;
                    ans.push_back(intervals[i]);
                    while(i+1<n && intervals[i+1][1]<b){
                        i++;
                    }
                }else{
                    ans.push_back(intervals[i]);
                }
            }
            return ans;
        }else{
            intervals[end][0]=a;
        }
        return intervals;
      }
      return ans;
    }
};
