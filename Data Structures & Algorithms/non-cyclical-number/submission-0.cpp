class Solution {
public:
    int sqsum(int n){
        int sum=0;
        while(n!=0){
            int d=n%10;
            sum+=d*d;
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
       while(n/10!=0){
        n = sqsum(n);
       }
       if(n==1 || n==7){
        return true;
       }else{
        return false;
       }
    }
};
