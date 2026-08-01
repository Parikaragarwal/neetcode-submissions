struct Node{
    int follows;
    int id;
};
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
         return a.second<b.second;
        };
        priority_queue<
        pair<Node,int>,
        vector<pair<Node,
        int>>,decltype(cmp)
        > pq(cmp);


        for(int following:following[userId]){
            vector<pair<int,int>> &twts = tweets[following];
            if(twts.size()>0){
                Node el;
                el.follows = following;
                el.id = (int)twts.size()-1;
                pq.push({el,twts[el.id].second});
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size()<10){
            Node el = pq.top().first;
            pq.pop();
            ans.push_back(tweets[el.follows][el.id].first);
            el.id--;
            if(el.id>=0){
                pq.push({el,tweets[el.follows][el.id].second});
            }
        }
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
