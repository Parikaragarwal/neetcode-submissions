class Solution {
public:
    int maxel(map<int,int,greater<int>> &mp){
        return mp.begin()->first;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1){
            return nums;
        }
        map<int,int,greater<int>> mp;
        int l=0;
        int r=0;
        vector<int> ans={};
        while(r<k){
            mp[nums[r]]++;
            r++;
        }
        ans.push_back(maxel(mp));
        while(r<nums.size()){
            mp[nums[r]]++;
            mp[nums[l]]--;
            if(mp[nums[l]]==0){
                mp.erase(nums[l]);
            }
            ans.push_back(maxel(mp));
            l++;
            r++;
        }
        return ans;
    }
};
