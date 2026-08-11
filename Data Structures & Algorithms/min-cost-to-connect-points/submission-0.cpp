class Solution {
public:
    int manhatten(vector<int> &a,vector<int> &b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n,false);
        vector<int> parents(n,-1);
        vector<int> mindis(n,INT_MAX);

        int cost = 0;
        int edgecount = 1;
        int curr = 0;
        
        while(edgecount!=n){
            visited[curr]= true;
            mindis[curr]=INT_MAX;
            for(int i=0;i<n;i++){
                if(visited[i]){
                    continue;
                }
                int mhd = manhatten(points[curr],points[i]);
                if(mhd<mindis[i]){
                    mindis[i]=mhd;
                    parents[i]=curr;
                }
            }
            int minid = curr ;
            for(int i=0;i<n;i++){
               if(mindis[i]<mindis[minid]){
                minid = i;
               }
            }
            curr = minid;
            cost += mindis[minid];
            edgecount++;
        }
        return cost;
    }
};
