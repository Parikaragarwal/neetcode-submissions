class Solution {
public:
    long long hash(vector<int> &n){
        sort(n.begin(),n.end());
        long long ans = 1;
        ans<<63;
        for(int i=0;i<3;i++){
            int el = n[i];
            ans = ans | el;
            ans = ans<<(2-i)*21;
        }
        return ans;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();


        unordered_set<long long> uni;
        vector<vector<int>> ans={};

        for(int i=0;i<size-2;i++){
            for(int j=i+1;j<size-1;j++){
                for(int k=j+1;k<size;k++){
                    int sum = nums[i]+nums[j]+nums[k];
                    if(sum==0){
                        vector<int> candidate = {nums[i],nums[j],nums[k]};
                        if(!uni.contains(hash(candidate))){
                             uni.insert(hash(candidate));
                             ans.push_back(candidate);
                        }     
                    }
                }
            }
        }
        return ans;
    }
};
