//good system design question

#include <bits/stdc++.h>
using namespace std;

class Twitter {
private:
    // Global timestamp
    int time;
    unordered_map<int, unordered_set<int>> following; // userId -> HashSet of people they follow
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> Vector of pairs {timestamp, tweetId}

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        // Store the tweet with the current timestamp, then increment the clock
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        // Min-Heap to keep the top 10 most recent tweets. 
        // Compares the first element of the pair (the timestamp).
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        
        // 1. Add the user's own recent tweets to the heap
        // We only need to check their last 10 tweets, not all of them
        int n = tweets[userId].size();
        for (int i = max(0, n - 10); i < n; ++i) {
            minHeap.push(tweets[userId][i]);
            if (minHeap.size() > 10) minHeap.pop();
        }
        
        // 2. Add the recent tweets of everyone they follow
        for (int followeeId : following[userId]) {
            int m = tweets[followeeId].size();
            for (int i = max(0, m - 10); i < m; ++i) {
                minHeap.push(tweets[followeeId][i]);
                if (minHeap.size() > 10) minHeap.pop();
            }
        }
        
        // 3. Extract the top 10 tweets from the heap
        vector<int> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        // The heap pops the oldest tweets first, so we must reverse the result 
        // to get them in descending order (newest to oldest)
        reverse(result.begin(), result.end());
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        // A user cannot follow themselves
        if (followerId != followeeId) {
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
