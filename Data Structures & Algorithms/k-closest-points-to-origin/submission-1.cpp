class Solution {
public:
    static int distance(vector<int> &point){
        int a=point[0];
        int b=point[1];

        return (a*a+b*b);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        auto cmp = [](vector<int> &a,
        vector<int> &b){
            return distance(a)<distance(b);
        };

        priority_queue<
        vector<int>,
        vector<vector<int>>,
        decltype(cmp)
        > pq(cmp,points);

        int rme = points.size()-k;
        while(rme--){
            pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
