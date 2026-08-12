class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distance(n,vector<int>(n,INT_MAX));
        vector<vector<int>> visited(n,vector<int>(n,false));

        int di[4]={0,-1,0,1};
        int dj[4]={-1,0,1,0};

        distance[0][0] = grid[0][0];

        auto cmp = [&distance](const auto &a,const auto &b){
            return distance[a.first][a.second]>distance[b.first][b.second];
        };

        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);

        pq.push({0,0});
        while(!pq.empty()){
            auto [i,j] = pq.top();
            visited[i][j]=true;
            pq.pop();

            for(int k=0;k<4;k++){
                int ci = i+di[k];
                int cj = j+dj[k];

                if(ci>=0 && cj>=0 && ci<n && cj<n && !visited[ci][cj]){
                   distance[ci][cj] = ( distance[i][j] +
                        max( 0, grid[ci][cj]-distance[i][j]) );
                   pq.push({ci,cj});
                }
            }
        }
        return distance[n-1][n-1];
    }
};
