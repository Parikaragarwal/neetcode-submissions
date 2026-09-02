class Solution {
public:
    double myPow(double x, int sn) {
        long long n = sn;

        if(n==0 || x==1.0) return 1.0;
        if(x==0.0) return 0.0;

        if(n<0){
            x=1.0/x;
            n=abs(n);
        }
        double curr = x;
        double ans = 1.0;
        while(n!=0){
            int include = n&1;
            n=n>>1;
            if(include){
                ans=ans*curr;
            }
            curr=curr*curr;
        }
        return ans;
        // double root = myPow(x,n/2);
        // if(n%2!=0){
        //     return root*root*x;
        // }
        // return root*root; 
        
    }
};
