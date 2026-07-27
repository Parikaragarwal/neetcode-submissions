class KthLargest {
    private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int kth;

public:
    KthLargest(int k, vector<int>& nums) {
        kth=k;
        int i=0;
        for(i=0;i<min(k,((int)nums.size()));i++){
            pq.push(nums[i]);
        }
        for(i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.push(nums[i]);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size()<kth){
            pq.push(val);
            return pq.top();
        }
        if(val>pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};
