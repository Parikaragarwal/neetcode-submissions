class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int zr = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(zr==-1){
                    if(matrix[i][j]==0){
                        zr = i;
                        break;
                    }
                }else{
                    if(matrix[i][j]==0){
                        matrix[zr][j]=0;
                        matrix[i][0]=0;
                    }
                }
            }
        }
        if(zr==-1){
            return;
        }
        for(int i=0;i<n;i++){
            if(i>zr && matrix[i][0]==0){
                for(int j=0;j<m;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<m;j++){
            if(matrix[zr][j]==0){
                for(int i=0;i<n;i++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<m;j++){
            matrix[zr][j]=0;
        }
    }
};
