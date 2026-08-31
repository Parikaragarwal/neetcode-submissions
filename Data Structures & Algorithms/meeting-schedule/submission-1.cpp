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
    bool canAttendMeetings(vector<Interval>& intervals) {
            sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
                return a.start<b.start;
            });
            int n = intervals.size();
            int prevend = INT_MIN;
            for(int i=0;i<n;i++){
                if(intervals[i].start<prevend){
                    return false;
                }else{
                    prevend = intervals[i].end;
                }
            }
            return true;
    }
};
