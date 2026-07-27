class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int> pq(nums.begin(),nums.end());
        // int n=k-1;
        // while(n--){
        //     pq.pop();
        // }
        // return pq.top();

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
