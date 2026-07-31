class Solution {
public:
    int partition(vector<int> &nums,int s,int e){
        int pid = s + rand() % (e - s + 1);
        int pivot = nums[pid];
        swap(nums[pid],nums[e]);
        int i=s;
        int j=e-1;
        while(true){
            while(i<e && nums[i]<pivot){
                i++;
            }
            while(j>=s && nums[j]>=pivot){
                j--;
            }
            if(i>=j){
                break;
            }
            swap(nums[i],nums[j]);
        }
        swap(nums[i],nums[e]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq(nums.begin(),nums.end());
        // int n=k-1;
        // while(n--){
        //     pq.pop();
        // }
        // return pq.top();
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int piv = partition(nums,s,e);
        while(n-piv!=k){
            int kth = n-piv;
            if(kth>k){
                piv = partition(nums,piv+1,e);
            }else{
                piv = partition(nums,s,piv-1);
            }
        }
        return nums[piv];

        priority_queue<int,vector<int>,greater<int>> pq;
        for(int el:nums){
            pq.push(el);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
