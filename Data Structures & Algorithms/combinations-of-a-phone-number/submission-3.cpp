class Solution {
public:
    void backtrack(
        string &digits,
        vector<string> &ans,
        int id,
        unordered_map<char,vector<char>> &mp,
        string &cand
    ){
        if(id==digits.size()){
            ans.push_back(cand);
            return;
        }
        
            vector<char> &els = mp[digits[id]];
            for(char el:els){
                cand.push_back(el);
                backtrack(digits,ans,id+1,mp,cand);
                cand.pop_back();
            }
        
    }
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

        vector<string> ans;
        string cand;

        backtrack(digits,ans,0,mp,cand);

        return ans;


        // queue<string> q;
        // q.push("");
        // for(char ch:digits){
        //     int size = q.size();
        //     for(int i=0;i<size;i++){
        //         string curr=q.front();
        //         q.pop();
        //         vector<char> &alp = mp[ch];
        //         for(char al:alp){
        //             string itmd = curr+al;
        //             q.push(itmd);
        //         }
        //     }
        // }
        // vector<string> ans;
        // while(!q.empty()){
        //     ans.push_back(q.front());
        //     q.pop();
        // }

        // return ans;
    }
};
