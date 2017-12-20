#include <vector>
#include <map>
#include <set>
#include <deque>
using namespace std;
/*
Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/
//这题看起来不难，真正做起来还是有点麻烦
//下面的solution未完成，留到第二遍的时候回忆当初的思路
class Twitter {
  public:
    /** Initialize your data structure here. */
    Twitter() {}

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        userSelfTweets[userId].push_back(tweetId);
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item
     * in the news feed must be posted by users who the user followed or by the
     * user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        for (auto it : userFollowers[userId]) {
        }
    }

    /** Follower follows a followee. If the operation is invalid, it should be a
     * no-op. */
    void follow(int followerId, int followeeId) {
        userFollowers[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be
     * a no-op. */
    void unfollow(int followerId, int followeeId) {
        userFollowers[followerId].erase(followeeId);
    }

  private:
    map<int, set<int>> userFollowers;
    map<int, vector<int>> userSelfTweets;
};

namespace s1 {
//最简单但是一般的答案
class Twitter {
  public:
    Twitter() { sn = 0; }

    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert(make_pair(sn++, tweetId));
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        map<int, int> top10;
        for (auto iter = userFollowers[userId].begin();
             iter != userFollowers[userId].end(); ++iter) {
            int followee = *iter;
            for (auto iter = tweets[followee].rbegin();
                 iter != tweets[followee].rend(); ++iter) {
                if (top10.size() > 0 && top10.begin()->first > iter->first &&
                    top10.size() >= 10)
                    break;
                top10.insert(make_pair(iter->first, iter->second));
                if (top10.size() > 10)
                    top10.erase(top10.begin());
            }
        }
        for (auto iter = top10.rbegin(); iter != top10.rend(); ++iter)
            result.push_back(iter->second);
        return result;
    }

    void follow(int followerId, int followeeId) {
        userFollowers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            userFollowers[followerId].erase(followeeId);
        }
    }

  private:
    map<int, set<int>> userFollowers;
    map<int, map<int, int>> tweets;
    long long sn = 0;
};
};