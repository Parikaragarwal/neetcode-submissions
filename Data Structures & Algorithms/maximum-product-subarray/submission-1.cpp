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
        int start=0;
        int ans = nums[0];
        bool zero = false;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero=true;
            }
            if(i+1==n || nums[i+1]==0){
                if(i+1<n){
                    zero=true;
                }
                ans = max(ans,maxprod(nums,start,i));
                start=i+2;
                i++;
            }
        }
        ans = zero?max(0,ans):ans;
        return ans;
    }
};
