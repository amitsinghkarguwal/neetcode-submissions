#include <unordered_map>
#include <list>

using namespace std;

class LFUCache {
private:
    int capacity;
    int min_freq;
    
    // key -> {value, frequency}
    unordered_map<int, pair<int, int>> key_val_freq; 
    
    // frequency -> Doubly Linked List of keys (Front = Most Recent, Back = Least Recent)
    unordered_map<int, list<int>> freq_list; 
    
    // key -> memory pointer to exactly where this key lives inside the freq_list
    unordered_map<int, list<int>::iterator> key_iter; 

    // Helper function to promote a key to the next frequency tier
    void promote(int key) {
        int current_freq = key_val_freq[key].second;
        
        // 1. Update the frequency tally
        key_val_freq[key].second++;
        
        // 2. Pluck it out of its current frequency list in O(1) time
        freq_list[current_freq].erase(key_iter[key]);
        
        // 3. If we just emptied out the lowest frequency tier, the minimum frequency goes up!
        if (freq_list[current_freq].empty() && min_freq == current_freq) {
            min_freq++;
        }
        
        // 4. Push it to the front of the next frequency tier
        freq_list[current_freq + 1].push_front(key);
        
        // 5. Save the new memory pointer
        key_iter[key] = freq_list[current_freq + 1].begin();
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        this->min_freq = 0;
    }
    
    int get(int key) {
        if (key_val_freq.find(key) == key_val_freq.end()) {
            return -1;
        }
        
        // Promote it because it was just accessed
        promote(key);
        return key_val_freq[key].first;
    }
    
    void put(int key, int value) {
        if (capacity <= 0) return;
        
        // If the key already exists, just update the value and promote it
        if (key_val_freq.find(key) != key_val_freq.end()) {
            key_val_freq[key].first = value;
            promote(key);
            return;
        }
        
        // If we are at capacity, we must execute an eviction
        if (key_val_freq.size() == capacity) {
            // The LRU item is always sitting at the back of the min_freq list
            int evict_key = freq_list[min_freq].back();
            
            freq_list[min_freq].pop_back();
            key_val_freq.erase(evict_key);
            key_iter.erase(evict_key);
        }
        
        // Insert the brand new key
        key_val_freq[key] = {value, 1};
        freq_list[1].push_front(key);
        key_iter[key] = freq_list[1].begin();
        
        // A new key always resets the absolute minimum frequency to 1
        min_freq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */