class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int least = INT_MAX;
        int sum = 0;
        int id = -1;
        for(int i=0;i<n;i++){
            sum+=gas[i]-cost[i];
            if(sum<least){
                least = sum;
                id = (i+1)%n;
            }
        }
        if(sum<0){
            return -1;
        }
        return id;
    }
};
