class Solution {
public:
    void valrotate(
        int &a,
        int &b,
        int &c,
        int &d
    ){
        int t = d;
        d=c;
        c=b;
        b=a;
        a=t;
    }
    void rotateouter(int s,int e,vector<vector<int>> &matrix){
        vector<vector<int>> ends = {
           {s,s},
           {s,e},
           {e,e},
           {e,s} 
        };
        for(int i=s;i<e;i++){
           valrotate(
            matrix[ends[0][0]][ends[0][1]++],
            matrix[ends[1][0]++][ends[1][1]],
            matrix[ends[2][0]][ends[2][1]--],
            matrix[ends[3][0]--][ends[3][1]]
           );
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int start=0;
        int end = n-1;
        while(start<end){
            rotateouter(start,end,matrix);
            start++;
            end--;
        }
    }
};
