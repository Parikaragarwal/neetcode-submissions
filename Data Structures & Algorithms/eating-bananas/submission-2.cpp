class Solution {
public:
    long long timeTaken(vector<int> &piles,int k){
        long long time=0;
            for(int pile:piles){
                time+=(int)ceil((double)pile/(double)k);
            }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx = piles[0];
        for(int el:piles){
            mx= max(mx,el);
        }
        // for(int k=1;k<=mx;k++){
        //     long long time=timeTaken(piles,k);
        //     if(time<=h){
        //         return k;
        //     }
        // }
        int start=1;
        int end=mx;

        while(start<end){
            int mid=start+(end-start)/2;
            long long time = timeTaken(piles,mid);
            if(time>h){
                start=mid+1;
            }else{
                end=mid;
            }
        }
        return end;
    }
};
