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
        int ans = 0;
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a.start<b.start;
        });
        auto cmp = [](const auto &a,const auto &b){
            return a.start<b.start;
        };
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            while(!pq.empty() && intervals[i].start>=pq.top()){
                pq.pop();
            }
        
            pq.push(intervals[i].end);
            ans = max(ans,(int)pq.size());
        }
        return ans;
    }
};
