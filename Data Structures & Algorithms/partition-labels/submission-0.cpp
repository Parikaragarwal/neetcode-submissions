class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int n = s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int start=i;
            int end = mp[s[i]];
            while(i<end){
                i++;
                if(i<n && mp[s[i]]>end){
                    end = mp[s[i]];
                }
            }
            ans.push_back(end-start+1);
        }
        return ans;
    }
};
