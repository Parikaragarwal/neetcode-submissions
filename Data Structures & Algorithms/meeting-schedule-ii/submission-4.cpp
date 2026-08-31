/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        // int ans = 0;
        // sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
        //     return a.start<b.start;
        // });
        // auto cmp = [](const auto &a,const auto &b){
        //     return a.start<b.start;
        // };
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(int i=0;i<n;i++){
        //     while(!pq.empty() && intervals[i].start>=pq.top()){
        //         pq.pop();
        //     }
        
        //     pq.push(intervals[i].end);
        //     ans = max(ans,(int)pq.size());
        // }
        // return ans;
        vector<int> start;
        vector<int> end;
        for(auto &inv: intervals){
            start.push_back(inv.start);
            end.push_back(inv.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int si=0;
        int ei=0;
        int count = 0;
        int ans = 0;
        while(si<n && ei<n){
            if(start[si]<end[ei]){
                count++;
                si++;
            }else{
                count--;
                ei++;

            }
            ans = max(ans,count);
        }
        return ans;
    }
};
