class Solution {
private:
int arrsum;
public:
    bool possible(
        vector<int> &nums,
        int sum,
        int id
    ){
        int n = nums.size();
        if(id==n || sum>arrsum/2){
            return false;
        }
        if(sum==arrsum/2){
            return true;
        }
        return possible(nums,sum+nums[id],id+1) || possible(nums,sum,id+1);
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        arrsum = sum;
        return possible(nums,0,0);
    }
};
