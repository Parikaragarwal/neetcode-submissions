class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<string> copy(strs);
       for(int i=0;i<copy.size();i++){
        sort(copy[i].begin(),copy[i].end());
       }

       unordered_map<string,vector<int>> groups;

       for(int i=0;i<copy.size();i++){
        groups[copy[i]].push_back(i);
       }

       vector<vector<string>> ans;

       for(auto group:groups){
        vector<int> ids = group.second;
        vector<string> ansGroup;
        for(int id:ids){
            ansGroup.push_back(strs[id]);
        }
        ans.push_back(ansGroup);
       }

       return ans;
    }
};
