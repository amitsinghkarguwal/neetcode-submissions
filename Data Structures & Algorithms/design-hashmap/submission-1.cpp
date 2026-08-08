class MyHashMap {
private:
    // Create an array large enough to hold the maximum possible key
    vector<int> map;
public:
    MyHashMap() {
        // Initialize the array with -1 (meaning no mapping exists)
        map.resize(1000001, -1);
    }
    
    void put(int key, int value) {
        map[key] = value;
    }
    
    int get(int key) {
        return map[key];
    }
    
    void remove(int key) {
        map[key] = -1;
    }
};