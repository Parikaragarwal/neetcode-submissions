class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& spd) {
       map<int,double> times;
       int n = pos.size();
       for(int i=0;i<n;i++){
        times[pos[i]]=(double)(target-pos[i])/(double)spd[i];
       }
       stack<int> s;
       int ans = 0;
       for(auto t:times){
        while(!s.empty() && times[s.top()]<=t.second){
            s.pop();
        }
        s.push(t.first);
       }
       return s.size();
    }
};
