class Solution {
void sortqueue(queue<string> &q){
    vector<string> strings;
    while(!q.empty()){
        strings.push_back(q.front());
        q.pop();
    }
    sort(strings.begin(),strings.end());
    for(string &el:strings){
        q.push(el);
    }
}
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string,queue<string>> mp;
        vector<string> ans;

        for(const auto &ticket:tickets){
            mp[ticket[0]].push(ticket[1]);
        }

        for(auto &it:mp){
            sortqueue(it.second);
        }

        stack<string> stk;
        stk.push("JFK");

        while(!stk.empty()){
            string curr = stk.top();
            queue<string> &q = mp[curr];
            if(!q.empty()){
                curr = q.front();
                q.pop();
                stk.push(curr);
            }else{
                ans.push_back(stk.top());
                stk.pop();
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;

        // string curr = "JFK";
        // ans.push_back(curr);
        
        // while(!mp[curr].empty()){
        //     queue<string> &nei = mp[curr];
        //     curr = nei.front();
        //     nei.pop();
        //     ans.push_back(curr);
        // }
        // return ans;
    }
};
