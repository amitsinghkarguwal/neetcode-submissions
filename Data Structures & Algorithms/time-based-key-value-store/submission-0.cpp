#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class TimeMap {
private:
    // Hash Map mapping a string key to a Vector of {timestamp, value} pairs
    unordered_map<string, vector<pair<int, string>>> store;

public:
    TimeMap() {
        // Initialization handled by default constructor
    }
    
    void set(string key, string value, int timestamp) {
        // Because timestamps only increase, this vector naturally stays sorted!
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        // If the key doesn't exist at all, return an empty string
        if (store.find(key) == store.end()) {
            return "";
        }
        
        const auto& values = store[key];
        int low = 0;
        int high = values.size() - 1;
        string result = "";
        
        // Binary Search to find the closest valid past timestamp
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // If the midpoint timestamp is valid (<= requested time)
            if (values[mid].first <= timestamp) {
                result = values[mid].second; // Record this as a potential answer
                low = mid + 1;               // Try to find an even closer (larger) valid time
            } else {
                high = mid - 1;              // search left
            }
        }
        return result;
    }
};
