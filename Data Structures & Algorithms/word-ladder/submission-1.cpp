class Solution {
   public:
    // bool pushclose(string& curr, queue<string>& q, unordered_set<string>& visited,
    //                unordered_set<string>& words, string& endword) {
    //     bool ans = false;
    //     string cmp = "abcdefghijklmnopqrstuvwxyz";
    //     for (int i = 0; i < curr.size(); i++) {
    //         char ch = curr[i];
    //         for (char replacement : cmp) {
    //             if (replacement != ch) {
    //                 curr[i] = replacement;
    //                 if (words.contains(curr) && !visited.contains(curr)) {
    //                     if (curr == endword) {
    //                         ans = true;
    //                     }
    //                     visited.insert(curr);
    //                     q.push(curr);
    //                 }
    //             }
    //         }
    //         curr[i] = ch;
    //     }
    //     return ans;
    // }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool ewp = false;
        for (const string& word : wordList) {
            if (word == endWord) {
                ewp = true;
                break;
            }
        }
        if (!ewp) {
            return false;
        }

        unordered_map<string, vector<string>> mp;
        wordList.push_back(beginWord);

        for (int i = 0; i < beginWord.size(); i++) {
            for (const string& word : wordList) {
                string copy = word;
                copy[i] = '*';
                mp[copy].push_back(word);
            }
        }

        queue<string> bq;
        queue<string> eq;

        unordered_set<string> bvisited;
        unordered_set<string> evisited;

        bq.push(beginWord);
        bvisited.insert(beginWord);
        eq.push(endWord);
        evisited.insert(endWord);
        int left = 1;
        int right = 1;

        while (!bq.empty() || !eq.empty()) {
            queue<string> *q;
            unordered_set<string> *visited;
            unordered_set<string> *ovisited;
            if (eq.size() == 0 || (bq.size() > 0 && bq.size() < eq.size())) {
                q = &bq;
                visited = &bvisited;
                ovisited = &evisited;
                left++;
            } else {
                q = &eq;
                visited = &evisited;
                ovisited = &bvisited;
                right++;
            }

            int size = q->size();
            for(int i=0;i<size;i++){
                string curr = q->front();
                q->pop();
                for(int k=0;k<beginWord.size();k++){
                    char val = curr[k];
                    curr[k]='*';
                    for(const string &nei:mp[curr]){
                    if(!visited->contains(nei)){
                        if(ovisited->contains(nei)){
                            return left+right-1;
                        }
                        visited->insert(nei);
                        q->push(nei);
                    }
                    curr[k]=val;
                }
                }
            }
        }

        return 0;

        // unordered_set<string> words;
        // for (const auto& word : wordList) {
        //     words.insert(word);
        // }
        // if (!words.contains(endWord)) {
        //     return 0;
        // }

        // unordered_set<string> visited;
        // queue<string> q;

        // q.push(beginWord);
        // int ans = 1;
        // while (!q.empty()) {
        //     int size = q.size();
        //     ans++;
        //     for (int l = 0; l < size; l++) {
        //         string curr = q.front();
        //         q.pop();
        //         if ( pushclose(curr, q, visited, words, endWord) ) {
        //             return ans;
        //         }
        //     }
        // }
        // return 0;
    }
};