//Bellman-Ford Algorithm

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Initialize prices to a very large number (infinity)
        const int INF = 1e9;
        vector<int> prices(n, INF);
        
        // The cost to reach the source is 0
        prices[src] = 0;
        
        // We can take up to k stops, which means k + 1 edges.
        for (int i = 0; i <= k; ++i) {
            // Create a temporary array for this iteration to prevent 
            // cascading updates that exceed the current edge limit.
            vector<int> tmpPrices = prices;
            
            for (const auto& flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int price = flight[2];
                
                // If the source node 'u' has been reached previously
                if (prices[u] != INF) {
                    // Update the destination node 'v' in the temporary array
                    if (prices[u] + price < tmpPrices[v]) {
                        tmpPrices[v] = prices[u] + price;
                    }
                }
            }
            
            // Set prices for the next iteration
            prices = tmpPrices;
        }
        
        // If the destination price is still infinity, it's unreachable within K stops
        return prices[dst] == INF ? -1 : prices[dst];
    }
};