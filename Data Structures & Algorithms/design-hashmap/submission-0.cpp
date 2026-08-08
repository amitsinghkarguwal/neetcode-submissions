#include <iostream>
#include <vector>
#include <list>

using namespace std;

class MyHashMap {
private:
    // The number of buckets. 
    int numBuckets;
    
    // An array of Linked Lists, where each node is a pair (key, value)
    vector<list<pair<int, int>>> buckets;

    // The Hash Function: Maps the key to a specific bucket index
    int hashFunction(int key) {
        return key % numBuckets;
    }

public:
    // Initialize the data structure
    MyHashMap() {
        numBuckets = 10000; 
        buckets.resize(numBuckets);
    }
    
    // Inserts a (key, value) pair. If the key already exists, update the value.
    void put(int key, int value) {
        int index = hashFunction(key);
        
        // Iterate through the linked list at this bucket
        for (auto& kv : buckets[index]) {
            if (kv.first == key) {
                // Key found, update the value and return immediately
                kv.second = value;
                return;
            }
        }
        
        // If the key wasn't found, append a new (key, value) pair to the list
        buckets[index].push_back({key, value});
    }
    
    // Returns the value to which the specified key is mapped, or -1 if no mapping exists
    int get(int key) {
        int index = hashFunction(key);
        
        // Iterate through the linked list to find the key
        for (auto& kv : buckets[index]) {
            if (kv.first == key) {
                return kv.second; // Return the associated value
            }
        }
        
        // Key not found
        return -1;
    }
    
    // Removes the key and its corresponding value if the map contains the mapping
    void remove(int key) {
        int index = hashFunction(key);
        
        // Use an iterator so we can safely erase the node if we find it
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};
