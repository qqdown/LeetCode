#pragma once
#include "leetcode.h"

namespace _355 {
	class Tweet {
	public:
		int userId;
		int tweetId;

	};

	class Twitter {
	public:
		/** Initialize your data structure here. */
		Twitter() {

		}

		/** Compose a new tweet. */
		void postTweet(int userId, int tweetId) {
			Tweet tw;
			tw.userId = userId;
			tw.tweetId = tweetId;
			tweets.push_back(tw);
		}

		/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
		vector<int> getNewsFeed(int userId) {
			vector<int> res;
			auto it = followedMap.find(userId);
			for (int i = tweets.size() - 1; i >= 0; i--) {
				if (tweets[i].userId == userId || (it != followedMap.end() && it->second.find(tweets[i].userId) != it->second.end())) {
					res.push_back(tweets[i].tweetId);
					if (res.size() == 10)
						break;
				}
			}
			return res;
		}

		/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
		void follow(int followerId, int followeeId) {
			if (followedMap.find(followerId) == followedMap.end()) {
				unordered_set<int> s;
				followedMap[followerId] = s;
			}
			followedMap[followerId].insert(followeeId);
		}

		/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
		void unfollow(int followerId, int followeeId) {
			if (followedMap.find(followerId) != followedMap.end()) {
				
				followedMap[followerId].erase(followeeId);
			}
		}

	private:
		unordered_map<int, unordered_set<int>> followedMap;
		vector<Tweet> tweets;
	};

	/**
	* Your Twitter object will be instantiated and called as such:
	* Twitter obj = new Twitter();
	* obj.postTweet(userId,tweetId);
	* vector<int> param_2 = obj.getNewsFeed(userId);
	* obj.follow(followerId,followeeId);
	* obj.unfollow(followerId,followeeId);
	*/
}