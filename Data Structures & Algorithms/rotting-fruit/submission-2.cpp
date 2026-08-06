class Solution {
private:

    long long hash(int i,int j){
        long long ans = 0;
        ans = ans | i;
        ans = ans<<32;
        ans = ans | j;
        return ans;
    }
    int bfs(
        vector<vector<int>>& grid,
        vector<pair<int,int>> &rotten,
        unordered_set<long long> &visited
    ){
        int n = grid.size();
        int m = grid[0].size();
        int di[4] = {1,0,-1,0};
        int dj[4] = {0,-1,0,1};

        queue<pair<int,int>> q;
        for(const auto [i,j]:rotten){
            visited.insert(hash(i,j));
            q.push({i,j});
        }
        int ans = -1;
        while(!q.empty()){
            int size = q.size();
            for(int l=0;l<size;l++){
                auto [ci,cj] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int i = ci + di[k];
                    int j = cj + dj[k];

                    if(i>=0 && j>=0 && i<n && j<m &&
                     !visited.count(hash(i,j)) &&
                       grid[i][j]==1
                       )
                    {
                        grid[i][j]=2;
                        visited.insert(hash(i,j));
                        q.push({i,j});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int,int>> rotten;
        unordered_set<long long> visited;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    rotten.push_back({i,j});
                }
            }
        }
        int ans = bfs(grid,rotten,visited);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(rotten.empty()){
            return 0;
        }
        return ans;
    }
};
