class Solution {
private:
    long long hash(int i,int j){
        long long ans = 0;
        ans = ans | i;
        ans = ans << 32;
        ans = ans | j;
        return ans;
    }

    vector<int> unhash(long long hsh){
        int i = (int)(hsh>>32);
        int j = (int)(hsh);
        return {i,j};
    }
public:
void applydfs(
    vector<vector<int>>& heights,
    int ci,
    int cj,
    unordered_set<long long> &visited
){
    int n = heights.size();
    int m = heights[0].size();
    int di[4] = {1,0,-1,0};
    int dj[4] = {0,1,0,-1};
    
    for(int k=0;k<4;k++){
        int i = ci+ di[k];
        int j = cj+ dj[k];

        if(i>=0 && j>=0 && i<n && j<m && heights[i][j]>=heights[ci][cj]
          && !visited.count(hash(i,j))){
            visited.insert(hash(i,j));
            applydfs(heights,i,j,visited);
          }
    }
}
void dfs(
        vector<vector<int>>& heights,
        vector<pair<int,int>> &start,
        unordered_set<long long> &visited
    ){
        for(const auto [i,j]:start){
            visited.insert(hash(i,j));
            applydfs(heights,i,j,visited);
        }
    }
    void bfs(
        vector<vector<int>>& heights,
        vector<pair<int,int>> &start,
        unordered_set<long long> &visited
    ){
        int n = heights.size();
        int m = heights[0].size();
        int di[4] = {1,0,-1,0};
        int dj[4] = {0,1,0,-1};

        queue<pair<int,int>> q;
        for(const auto [i,j]:start){
            q.push({i,j});
            visited.insert(hash(i,j));
        }

        while(!q.empty()){
            auto [id,jd] = q.front();
            q.pop();
            int val = heights[id][jd];
            for(int k=0;k<4;k++){
                int i = id + di[k];
                int j = jd + dj[k];

                if(
                   i>=0 && j>=0 && i<n && j<m &&
                   heights[i][j]>=val &&
                   !visited.count(hash(i,j))
                  ){
                    visited.insert(hash(i,j));
                    q.push({i,j});
                  }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        unordered_set<long long> pacific;
        unordered_set<long long> atlantic;

        int n = heights.size();
        int m = heights[0].size();

        vector<pair<int,int>> pc;
        vector<pair<int,int>> at;

        for(int i=0;i<n;i++){
            pc.push_back({i,0});
            at.push_back({i,m-1});
        }

        for(int j=0;j<m;j++){
            pc.push_back({0,j});
            at.push_back({n-1,j});
        }

        dfs(heights,pc,pacific);
        dfs(heights,at,atlantic);

        vector<vector<int>> ans;
        auto [smaller,larger] = pacific.size()<atlantic.size()
        ?std::tie(pacific,atlantic)
        :std::tie(atlantic,pacific);

        for(const long long el:smaller){
            if(larger.count(el)){
                ans.push_back(unhash(el));
            }
        }
        return ans;
        
    }
};
