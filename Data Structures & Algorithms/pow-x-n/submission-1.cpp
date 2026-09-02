class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        if(n<0){
            x=1.0/x;
            n=abs(n);
        }
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }

        double root = myPow(x,n/2);
        if(n%2!=0){
            return root*root*x;
        }
        return root*root; 
        
    }
};
