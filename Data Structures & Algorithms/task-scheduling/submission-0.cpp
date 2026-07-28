class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        auto cmp = [](const pair<int,int> &a,const pair<int,int> &b){
            return a.second<b.second;
        };

        vector<int> feq(26,0);
        for(char task:tasks){
            feq[task-'A']++;
        }

        priority_queue<
        pair<int,int>
        ,vector<pair<int,int>>
        ,decltype(cmp)> pq(cmp);

        for(int i=0;i<26;i++){
            if(feq[i]>0){
                pq.push({i,feq[i]});
            }
        }

        queue<pair<int,int>> q;
        int t=0;
        while(!q.empty() || !pq.empty()){

            while(!q.empty() && q.front().second==t){
                int id = q.front().first;
                pq.push({id,feq[id]});
                q.pop();
            }

            if(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int id = curr.first;
            curr.second--;
            feq[curr.first]--;
            if(curr.second>0)
            q.push({id,t+1+n});
            }
            t++;
        }
        return t;
    }
};
