class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits==""){
            return {};
        }
        unordered_map<char,vector<char>> mp;
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        queue<string> q;
        q.push("");
        for(char ch:digits){
            int size = q.size();
            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                vector<char> &alp = mp[ch];
                for(char al:alp){
                    string itmd = curr+al;
                    q.push(itmd);
                }
            }
        }
        vector<string> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
