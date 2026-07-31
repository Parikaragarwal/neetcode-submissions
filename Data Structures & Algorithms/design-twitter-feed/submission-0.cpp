class Twitter {
private:

int time;
unordered_map<int,vector<pair<int,int>>> tweets;
unordered_map<int,unordered_set<int>> following;


public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        auto it = tweets.find(userId);
        if(it==tweets.end()){
            following[userId].insert(userId);
            tweets[userId].push_back({tweetId,time});
            time++;
            return;
        }
        it->second.push_back({tweetId,time});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        following[userId].insert(userId);
        auto cmp = [](const auto &a,const auto &b){
         return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
        for(int following:following[userId]){
            for(auto &tweet:tweets[following]){
                
                pq.push(tweet);

                if(pq.size()>10){
                    pq.pop();
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        following[followerId].erase(followeeId);
    }
};
