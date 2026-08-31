class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a[1]!=b[1]?a[1]<b[1]:a[0]<b[0];
        });
        int n = intervals.size();
        int keep=0;
        int prevend = INT_MIN;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=prevend){
                keep++;
                prevend=intervals[i][1];
            }
        }
        return n-keep;
    }
};
