#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    // map to store graph adjacency list
    unordered_map<char, unordered_set<char>> adj;
    // map to track visited states: 0 = unvisited, 1 = visiting, 2 = visited
    unordered_map<char, int> visited; 
    string result = "";

    // DFS function to perform topological sorting and cycle detection
    bool dfs(char c) {
        if (visited.count(c)) {
            return visited[c] == 2; // Returns true if fully processed, false if cycle (visiting)
        }

        visited[c] = 1; // Mark as currently visiting (in recursion stack)

        for (char neighbor : adj[c]) {
            if (!dfs(neighbor)) {
                return false; // Cycle detected in a neighbor's path
            }
        }

        visited[c] = 2; // Mark as fully visited
        result.push_back(c); // Post-order tracking
        return true;
    }

public:
    string foreignDictionary(vector<string>& words) {
        // Step 1: Initialize graph with all unique characters
        for (const string& word : words) {
            for (char c : word) {
                adj[c] = unordered_set<char>();
            }
        }

        // Step 2: Build the directed edges from adjacent words
        for (size_t i = 0; i < words.size() - 1; ++i) {
            string w1 = words[i];
            string w2 = words[i + 1];
            size_t minLen = min(w1.length(), w2.length());

            // Check prefix edge case: if w1 is longer than w2 but starts with w2 (e.g., "abc", "ab")
            if (w1.length() > w2.length() && w1.compare(0, minLen, w2, 0, minLen) == 0) {
                return ""; 
            }

            // Find the first differing character to draw a dependency edge
            for (size_t j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break; // Only the first mismatch tells us the relative order
                }
            }
        }

        // Step 3: Run DFS on all unique characters
        for (const auto& pair : adj) {
            char c = pair.first;
            if (visited.find(c) == visited.end()) {
                if (!dfs(c)) {
                    return ""; // Cycle detected, order is impossible
                }
            }
        }

        // Step 4: Post-order list must be reversed to achieve true topological order
        reverse(result.begin(), result.end());
        return result;
    }
};
