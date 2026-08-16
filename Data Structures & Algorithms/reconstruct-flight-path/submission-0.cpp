#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Step 1: Build the adjacency list
        unordered_map<string, vector<string>> adj;
        for (const auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);
        }
        
        // Step 2: Sort the destinations in descending lexical order.
        // This allows us to efficiently use pop_back() to get the smallest lexical string.
        for (auto& [src, dests] : adj) {
            sort(dests.rbegin(), dests.rend());
        }
        
        vector<string> itinerary;
        
        // Step 3: Run Hierholzer's Algorithm (Post-Order DFS)
        dfs("JFK", adj, itinerary);
        
        // Step 4: The DFS builds the path in reverse, so we reverse it back
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
    
private:
    void dfs(const string& airport, unordered_map<string, vector<string>>& adj, vector<string>& itinerary) {
        auto& dests = adj[airport];
        
        // While there are still outgoing flights from this airport
        while (!dests.empty()) {
            // Greedily pick the alphabetically smallest destination
            string nextAirport = dests.back();
            dests.pop_back(); // Remove the ticket so we don't use it again
            
            dfs(nextAirport, adj, itinerary);
        }
        
        // Once an airport has no more outgoing flights, it gets added to the itinerary
        itinerary.push_back(airport);
    }
};
