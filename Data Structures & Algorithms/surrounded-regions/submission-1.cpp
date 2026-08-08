class Solution {
public:
    void bfs(
        vector<vector<char>>& board,
        vector<pair<int,int>> &start
    ){
        int n = board.size();
        int m = board[0].size();
        int di[4]={-1,0,1,0};
        int dj[4]={0,-1,0,1};

        queue<pair<int,int>> q;

        for(const auto [i,j]:start){
            board[i][j]='K';
            q.push({i,j});
        }

        while(!q.empty()){
            auto [ci,cj] = q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int i = ci+di[k];
                int j = cj+dj[k];

                if(i>=0 && j>=0 && i<n && j<m && board[i][j]=='O'){
                    board[i][j]='K';
                    q.push({i,j});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<pair<int,int>> start;
        for(int i=0;i<n;i++){
            if(board[i][0]=='O')
            start.push_back({i,0});

            if(board[i][m-1]=='O')
            start.push_back({i,m-1});
        }

        for(int j=1;j<m-1;j++){
            if(board[0][j]=='O')
            start.push_back({0,j});

            if(board[n-1][j]=='O')
            start.push_back({n-1,j});
        }
        bfs(board,start);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='K'){
                    board[i][j]='O';
                }
            }
        }
    }
};
