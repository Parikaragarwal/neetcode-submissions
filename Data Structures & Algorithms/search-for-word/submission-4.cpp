class Solution {
public:
    long long hash(int i,int j){
        long long ans = 0;
        ans = (ans | i);
        ans = (ans<<32);
        ans = (ans | j);
        return ans;
    }
    bool backtrack(
        vector<vector<char>>& board,
        int i,
        int j,
        int n,
        int m,
        int id,
        string &word,
        unordered_set<long long> &visited
    ){
        if(id==word.size()){
            return true;
        }
        if(i>=n || j>=m || i<0 || j<0 || word[id]!=board[i][j] 
        || visited.contains(hash(i,j))){
            return false;
        }

        vector<pair<int,int>> go = {
            {i+1,j},
            {i,j+1},
            {i-1,j},
            {i,j-1}
        };
        bool ans = false;
        long long hsh = hash(i,j);
        visited.insert(hsh);
        for(const auto &g:go){
            ans= ans || backtrack(board,g.first,g.second,n,m,id+1,word,visited);
        }
        visited.erase(hsh);
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        unordered_set<long long> visited;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(backtrack(board,i,j,n,m,0,word,visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
