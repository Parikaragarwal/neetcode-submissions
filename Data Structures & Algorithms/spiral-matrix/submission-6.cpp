class Solution {
public:
    void iterate(vector<int> index,int var,int end,
    vector<int> &ans,bool inc,
    vector<vector<int>> &matrix){
       
        while(true){
            if(index[var]==end){
                ans.push_back(matrix[index[0]][index[1]]);
                break;
            }
            ans.push_back(matrix[index[0]][index[1]]);
            if(inc){
                index[var]++;
            }else{
                index[var]--;
            }
        }
    }
    void addlayer(int s,int re,int ce,vector<vector<int>> &matrix,vector<int> &ans){
        if(s==re || s==ce){
            if(s==re && s==ce){
               ans.push_back(matrix[s][re]);
               return;
            }
        if(s!=re){
        for(int i=s;i<=re;i++){
            ans.push_back(matrix[s][i]);
        }
        }else{
        for(int i=s;i<=ce;i++){
            ans.push_back(matrix[i][s]);
        }
        }
        return;
        }
        if(s<=re-1) iterate({s,s}  ,1, re-1 ,ans,true,matrix);
        if(s<=ce-1) iterate({s,re} ,0, ce-1 ,ans,true,matrix);
        if(re>=s+1) iterate({ce,re},1, s+1  ,ans,false,matrix);
        if(ce>=s+1) iterate({ce,s} ,0, s+1  ,ans,false,matrix);
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int start=0;
       int n = matrix.size();
       int m = matrix[0].size();
       int colend = n-1;
       int rowend = m-1;
       vector<int> ans;
       while(start<=rowend && start<=colend){
         addlayer(start,rowend,colend,matrix,ans);
         start++;
         rowend--;
         colend--;
       }
       int s = start;
       int re = rowend;
       int ce = colend;
    
       return ans;
    }
};
