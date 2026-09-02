struct PairHash {
    size_t operator()(pair<int, int> p) const {
        return ((size_t)(uint32_t)p.first << 32) | (uint32_t)p.second;
    }
};
class CountSquares {
private:
 unordered_map<pair<int,int>,int,PairHash> points;
 // for any given y all its x co-ordinates;
 unordered_map<int,unordered_set<int>> xc;

public:
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[{x,y}]++;
        xc[y].insert(x);
    }
    
    int count(vector<int> point) {
        int a = point[0];
        int b = point[1];
        int ans = 0;
        for(int x:xc[b]){
            if(x==a){
                continue;
            }
            int y1 = b-abs(x-a);
            int y2 = b+abs(x-a);

            if(points.contains({a,y1}) && points.contains({x,y1})){
                ans+=points[{x,b}]*points[{x,y1}]*points[{a,y1}];
            }
            if(points.contains({a,y2}) && points.contains({x,y2})){
                ans+=points[{x,b}]*points[{x,y2}]*points[{a,y2}];
            }
        }
        return ans;
    }
};
