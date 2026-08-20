class Solution {
private:
    bool possible(
        vector<int> &nums,
        int sum,
        int id
    ){
        int n = nums.size();
        if(id==n || sum<0){
            return false;
        }
        if(sum==0){
            return true;
        }
        return possible(nums,sum-nums[id],id+1) || possible(nums,sum,id+1);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0){
            return false;
        }
        return possible(nums,sum/2,0);
    }
};
