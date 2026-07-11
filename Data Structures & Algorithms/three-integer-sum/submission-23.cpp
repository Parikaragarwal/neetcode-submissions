class Solution {
public:
    // long long hash(vector<int> &n){
    //     sort(n.begin(),n.end());
    //     long long ans = 1;
    //     ans<<63;
    //     for(int i=0;i<3;i++){
    //         int el = n[i];
    //         ans = ans | el;
    //         ans = ans<<(2-i)*21;
    //     }
    //     return ans;
    // }
    long long hash(int a,int b){
        int first = a<b?a:b;
        int second = a+b-first;
        long long ans = 0;
        ans = ans | first;
        ans = ans<<32;
        ans = ans | second;
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();


        // unordered_set<long long> uni;
        // vector<vector<int>> ans={};

        // for(int i=0;i<size-2;i++){
        //     for(int j=i+1;j<size-1;j++){
        //         for(int k=j+1;k<size;k++){
        //             int sum = nums[i]+nums[j]+nums[k];
        //             if(sum==0){
        //                 vector<int> candidate = {nums[i],nums[j],nums[k]};
        //                 if(!uni.contains(hash(candidate))){
        //                      uni.insert(hash(candidate));
        //                      ans.push_back(candidate);
        //                 }     
        //             }
        //         }
        //     }
        // }
        // return ans;








        // unordered_map<int,int> f;
        // unordered_set<long long> s;
        // vector<vector<int>> ans={};
        // for(int el:nums){
        //     f[el]++;
        // }
        
                        
        // for(int i=0;i<size-1;i++){
        //     for(int j=i+1;j<size;j++){
        //         int a = nums[i];
        //         int b = nums[j];
        //         int c = (a+b)*-1;
        //         if(c==0){
        //             continue;
        //         }
        //         bool needtwo = (a==c || b==c);
        //         vector<int> can = {a,b,c};
        //         if(
        //          !(s.contains(hash(can))) 
        //          && f.contains(c)
        //          && (!needtwo || f[c]>=2))
        //         {
        //             s.insert(hash(can));
        //             ans.push_back({a,b,c});
        //         }
        //     }
        // }
        // vector<int> cand= {0,0,0};
        // if(f[0]>=3 && !s.contains(hash(cand))){
        //     ans.push_back({0,0,0});
        // }
        // return ans;

        
        // 
        

        vector<vector<int>> ans ={};
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-2;i++){
            if(i>=1 && nums[i]==nums[i-1]){
                continue;
            }
            
            int s = i+1;
            int e = size-1;
            int target = -(nums[i]);
            while(s<e){
                if(s>i+1 && nums[s-1]==nums[s]){
                    s++;
                    continue;
                }
                if(e<size-1 && nums[e+1]==nums[e]){
                    e--;
                    continue;
                }
                int sum = nums[s]+nums[e];
                if(sum==target){
                    ans.push_back({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }else if(sum<target){
                    s++;
                }else{
                    e--;
                }
            }
        }
        return ans;
    }
};
