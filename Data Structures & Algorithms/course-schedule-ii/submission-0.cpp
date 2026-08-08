class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int,vector<int>> mp;
        vector<int> indeg(numCourses,0);

        for(const auto &preq: prerequisites){
            int a = preq[0];
            int b = preq[1];
            mp[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for(int preq:mp[course]){
                indeg[preq]--;
                if(indeg[preq]==0){
                    q.push(preq);
                }
            }
        }
        if(ans.size()<numCourses){
            return {};
        }
        return ans;
    }
};
