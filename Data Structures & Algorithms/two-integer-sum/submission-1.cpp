class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int size = nums.size();

    //   for(int i=0;i<size-1;i++){
    //     for(int j=i+1;j<size;j++){
    //         if(nums[i]+nums[j]==target){
    //             return {i,j};
    //         }
    //     }
    //   }  
    //   return {-1,-1};


    vector<int> copy(nums);

    sort(copy.begin(),copy.end());
    int i=0,j=size-1;

    while(i<j){
        int sum = copy[i]+copy[j];
        if(sum<target){
            i++;
        }else if(sum>target){
            j--;
        }else{
            break;
        }
    }
    if(i==j){
        return {-1,-1};
    }
    vector<int> ans;
    for(int k=0;k<size;k++){
      if(nums[k]==copy[i] || nums[k]==copy[j]){
        ans.push_back(k);
      }
    }
    sort(ans.begin(),ans.end());
    return ans;

    }
};
