class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = piles[0];
        for(int el:piles){
            mx= max(mx,el);
        }
        for(int k=1;k<=mx;k++){
            long long time=0;
            for(int pile:piles){
                time+=(int)ceil((double)pile/(double)k);
            }
            if(time<=h){
                return k;
            }
        }
        return -1;
    }
};
