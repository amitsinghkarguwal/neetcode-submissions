class MyHashSet {
private:
    // The number of buckets. A prime number or a reasonably large number 
    // helps distribute the keys evenly to minimize collisions.
    int numBuckets;
    
    // An array of Linked Lists (Separate Chaining)
    vector<list<int>> buckets;

    // The Hash Function: Maps the key to a specific bucket index
    int hashFunction(int key) {
        return key % numBuckets;
    }

public:
    // Initialize the data structure
    MyHashSet() {
        numBuckets = 10000; 
        buckets.resize(numBuckets);
    }
    
    // Inserts the value key into the HashSet
    void add(int key) {
        int index = hashFunction(key);
        // Check if the key already exists in this bucket's linked list
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        
        // If it does not exist, add it to the list
        if (it == buckets[index].end()) {
            buckets[index].push_back(key);
        }
    }
    
    // Removes the value key in the HashSet. If key does not exist, do nothing
    void remove(int key) {
        int index = hashFunction(key);
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        
        // If we found the key, erase it from the linked list
        if (it != buckets[index].end()) {
            buckets[index].erase(it);
        }
    }
    
    // Returns true if this set contains the specified element
    bool contains(int key) {
        int index = hashFunction(key);
        auto it = find(buckets[index].begin(), buckets[index].end(), key);
        
        // Return true if the iterator doesn't point to the end of the list
        return it != buckets[index].end();
    }
};