class Solution {
public:
    bool isValidBox(vector<vector<char>>& board,int r,int c){
      vector<bool> found(board.size(),false);
      int bxsz = sqrt(board.size());
      for(int i=r;i<r+bxsz;i++){
        for(int j=c;j<c+bxsz;j++){

          if(board[i][j]=='.'){
            continue;
          }
        
             if(found[(board[i][j]-'0')-1]){
              return false;
             }else{
              found[(board[i][j]-'0')-1]=true;
             }
          
        }
      }
      return true;
    }

    bool isValidRow(vector<char> &row){
      vector<bool> found(row.size(),false);
      for(char s:row){
        if(s=='.'){
          continue;
        }
        if(found[(s-'0')-1]){
          return false;
        }else{
          found[(s-'0')-1]=true;
        }
      }
      return true;
    }

    bool isValidCol(vector<vector<char>>& board,int colid){
      vector<bool> found(board.size(),false);
      for(int i=0;i<board.size();i++){

        if(board[i][colid]=='.'){
            continue;
          }
        
             if(found[(board[i][colid]-'0')-1]){
              return false;
             }else{
              found[(board[i][colid]-'0')-1]=true;
             }
      }
      return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();
        int bxsz = sqrt(size);

        bool ans = true;

        for(int i=0;i<size;i++){
          ans=ans&&isValidCol(board,i);
        }

        for(int i=0;i<size;i++){
          ans=ans&&isValidRow(board[i]);
        }

        for(int i=0;i<bxsz;i++){
          for(int j=0;j<bxsz;j++){
            ans = ans && isValidBox(board,i*bxsz,j*bxsz);
          }
        }

        return ans;
    }
};
