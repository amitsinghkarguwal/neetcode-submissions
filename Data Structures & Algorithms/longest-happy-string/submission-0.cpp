#include <string>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        // Max-Heap storing pairs of {count, character}
        priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        while (!pq.empty()) {
            // Get the most abundant character
            auto [count1, char1] = pq.top(); 
            pq.pop();
            
            int n = result.length();
            
            // Check if placing char1 would cause three-in-a-row
            if (n >= 2 && result[n - 1] == char1 && result[n - 2] == char1) {
                
                // We must use the second most abundant character instead
                if (pq.empty()) {
                    // No other characters left to break the streak. We are done!
                    break;
                }
                
                auto [count2, char2] = pq.top(); 
                pq.pop();
                
                // Place the fallback character
                result += char2;
                
                // If we still have more of char2, put it back
                if (--count2 > 0) {
                    pq.push({count2, char2});
                }
                
                // We didn't use char1, so put it back into the heap untouched
                pq.push({count1, char1});
                
            } else {
                // Safe to place the most abundant character
                result += char1;
                
                // If we still have more of char1, put it back
                if (--count1 > 0) {
                    pq.push({count1, char1});
                }
            }
        }
        
        return result;
    }
};