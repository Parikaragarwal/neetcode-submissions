class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    //    int n = nums.size();
    //    for(int i=0;i<n-1;i++){
    //     for(int j=i+1;j<n;j++){
    //         if(nums[i]==nums[j]){
    //             return true;
    //         }
    //     }
    //    }
    //    return false;

    //  int n= nums.size();
    //    sort(nums.begin(),nums.end());

    //    for(int i=0;i<n-1;i++){
    //     if(nums[i]==nums[i+1]){
    //         return true;
    //     }
    //    }
    //    return false;


    // set<int> visited;
    // for(int curr: nums){
    //     if(visited.contains(curr)){
    //         return true;
    //     }
    //     visited.insert(curr);
    // }
    // return false;
    // }

    // Unoptimal as set is balanced BST
    // Need Hash Set

    unordered_set<int> visited;
    for(int curr: nums){
        if(visited.contains(curr)){
            return true;
        }
        visited.insert(curr);
    }
    return false;
    }
};