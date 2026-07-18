class Solution {
    pair<int,int> increase(pair<int,int> el,int n,int m){
        int i=el.first;
        int j=el.second;
        if(j<m-1){
            return {i,j+1};
        }else{
            return {i+1,0};
        }
    }
    pair<int,int> decrease(pair<int,int> el,int n,int m){
        int i=el.first;
        int j=el.second;
        if(j>0){
            return {i,j-1};
        }else{
            return {i-1,j};
        }
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        // pair<int,int> start={0,0};
        // pair<int,int> end={n-1,m-1};

        // while(start.first!=end.first || start.second!=end.second){
        //     // pair<int,int> mid = {
        //     //     start.first+(end.first-start.first)/2,
        //     //     start.second+(end.second-start.second)/2
        //     //     };
        //      pair<int,int> mid = {
        //         start.first+(end.first-start.first)/2,
        //         (((end.first-start.first)*m+(end.second-start.second)+1)/2)%m-1
        //      };

        //     int currVal = matrix[mid.first][mid.second];

        //     if(currVal==target){
        //         return true;
        //     }else if(currVal<target){
        //         start=increase(mid,n,m);
        //     }else{
        //         end=decrease(mid,n,m);
        //     }
        // }
        // return false;


        int start = 0;
        int end = (n-1)*m+m-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            int i=mid/m;
            int j=mid%m;
            int currVal =matrix[i][j];

            if(currVal==target){
                return true;
            }else if(currVal<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }
};
