class Solution {
public:
    static bool comparePairs(const pair<int,int> &p1, const pair<int,int> &p2){
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {


      // unordered_map<int,int> feq;
      
      // for(int el:nums){
      //   feq[el]++;
      // }
      // vector<pair<int,int>> f;
      // for(auto it:feq){
      //   f.push_back({it.first,it.second});
      // }
      // sort(f.begin(),f.end(),comparePairs);
      // vector<int> ans;
      // for(int i=0;i<k;i++){
      //   ans.push_back(f[i].first);
      // }
      // return ans;
      int size = nums.size();
      vector<vector<int>> fqEl(size+1,vector<int> {});
      unordered_map<int,int> feq;
      
      for(int el:nums){
        feq[el]++;
      }
      for(auto it:feq){
        fqEl[it.second].push_back(it.first);
      }
      vector<int> ans={};
      while(k){
        if(fqEl[size].size()>0){
          for(int el:fqEl[size]){
            ans.push_back(el);
            k--;
          }
        }
        size--;
      }

      return ans;

    }
};
