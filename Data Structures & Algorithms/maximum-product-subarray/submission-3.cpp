class Solution {
private:
    int maxprod(vector<int> &nums,int start,int end){
        int n = end-start+1;
        int prev=1;
        int suff=1;
        int ans = nums[start];

        for(int i=start;i<=end;i++){
            prev = prev*nums[i];
            ans = max(ans,prev);
        }
        for(int i=end;i>=start;i--){
            suff = suff*nums[i];
            ans = max(ans,suff);
        }
        return ans;
    }
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int mi = 0;
        int Mi = 0;
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(mi==0 && Mi==0 && x!=0){
                mi=x;
                Mi=x;
                ans = max(ans,Mi);
                continue;
            }
            int cmi = mi;
            int cMi = Mi;
            mi = min(x,min(cmi*x,cMi*x));
            Mi = max(x,max(cmi*x,cMi*x));
            ans = max(ans,Mi);
        }
        return ans;
        
        // int start=0;
        // int ans = nums[0];
        // bool zero = false;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         zero=true;
        //         start=i+1;
        //         continue;
        //     }
        //     if(i+1==n || nums[i+1]==0){
        //         if(i+1<n){
        //             zero=true;
        //         }
        //         ans = max(ans,maxprod(nums,start,i));
        //         start=i+2;
        //         i++;
        //     }
        // }
        // ans = zero?max(0,ans):ans;
        // return ans;
    }
};
