class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> neighbors(n);
        vector<bool> visited(n,false);
        vector<int> distance(n,INT_MAX);
        auto cmp = [](const auto &a,const auto &b){
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        k=k-1;
        distance[k]=0;
        pq.push({k,0});

        for(const auto &edge:times){
           int a = edge[0]-1;
           int b = edge[1]-1;
           int time = edge[2];
           neighbors[a].push_back({b,time});
        }

        while(!pq.empty()){
            auto [el,dis] = pq.top();
            pq.pop();
            if(distance[el]<dis){
                continue;
            }
            visited[el]=true;
            for(auto [neighbor,rt]:neighbors[el]){
                if(visited[neighbor]){
                    continue;
                }
               int dtn = distance[neighbor];
               distance[neighbor] = min(distance[el]+rt,dtn);
               if(distance[neighbor]<dtn){
                pq.push({neighbor,distance[neighbor]});
               }
            }
        }

        int ans = INT_MIN;
        for(int d:distance){
            ans = max(d,ans);
        }
        return ans==INT_MAX?-1:ans;
    }
};
