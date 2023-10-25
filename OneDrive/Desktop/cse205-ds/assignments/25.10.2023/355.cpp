class Twitter {
public:
    unordered_map<int,unordered_map<int,int>> follows;
    vector<pair<int,int>> posts;

    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int cnt=0;
        for(int i=posts.size()-1; i>=0 && cnt<10; i--){
            if(posts[i].first==userId || follows[userId][posts[i].first]){
                feed.push_back(posts[i].second);
                cnt++;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId][followeeId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId][followeeId]=0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */