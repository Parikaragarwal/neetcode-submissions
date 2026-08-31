class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        map<int,int> mp;
        for(int el:queries){
            mp[el]=-1;
        }
        int i=0;
        auto cmp = [](auto &a,auto &b){
            return a.first>b.first;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(auto &it:mp){
            int query = it.first;
            while(i<n && intervals[i][0]<=query){
                int a = intervals[i][0];
                int b = intervals[i][1];
                pq.push({(b-a+1),b});
                i++;
            }
            while(!pq.empty() && pq.top().second<query){
                pq.pop();
            }
            if(!pq.empty()){
                it.second=pq.top().first;
            }
        }
        vector<int> ans;
        for(int q:queries){
            ans.push_back(mp[q]);
        }
        return ans;
    }
};
