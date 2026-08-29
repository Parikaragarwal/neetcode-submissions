class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int> feq;
        for(int card:hand){
            feq[card]++;
        }
        while(!feq.empty()){
            auto it = feq.begin();
            int key = it->first;
            for(int i=0;i<groupSize;i++){
                int val = feq[key];
                val--;
                if(val==0){
                    feq.erase(key);
                }else{
                    feq[key]=val;
                }

                int next = key+1;
                if(i==groupSize-1){
                    continue;
                }
                if(feq.contains(next)){
                    key = next;
                    val = feq[key];
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
