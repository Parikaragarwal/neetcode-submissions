class Solution {
   public:
    bool pushclose(
        string& curr,
        queue<string>& q,
        unordered_set<string>& visited,
        unordered_set<string>& words,
        string& endword
        ) {
        bool ans = false;
        string cmp = "abcdefghijklmnopqrstuvwxyz";
        for (int i = 0; i < curr.size(); i++) {
            char ch = curr[i];
            for (char replacement : cmp) {
                if (replacement != ch) {
                    curr[i] = replacement;
                    if (words.contains(curr) && !visited.contains(curr)) {
                        if (curr == endword) {
                            ans = true;
                        }
                        visited.insert(curr);
                        q.push(curr);
                    }
                }
            }
            curr[i] = ch;
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for (const auto& word : wordList) {
            words.insert(word);
        }
        if (!words.contains(endWord)) {
            return 0;
        }

        unordered_set<string> visited;
        queue<string> q;

        q.push(beginWord);
        int ans = 1;
        while (!q.empty()) {
            int size = q.size();
            ans++;
            for (int l = 0; l < size; l++) {
                string curr = q.front();
                q.pop();
                if ( pushclose(curr, q, visited, words, endWord) ) {
                    return ans;
                }
            }
        }
        return 0;
    }
};