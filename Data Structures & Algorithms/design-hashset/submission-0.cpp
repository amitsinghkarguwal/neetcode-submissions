class MyHashSet {
private:
    vector<bool> set;
public:
    MyHashSet() {
        // Create an array large enough to hold the maximum possible key
        set.resize(1000001, false);
    }
    
    void add(int key) {
        set[key] = true;
    }
    
    void remove(int key) {
        set[key] = false;
    }
    
    bool contains(int key) {
        return set[key];
    }
};