#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    
    // We store the key in the node so we know which entry to delete 
    // from the Hash Map when the node is evicted.
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}  //new way to make a function.
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // Maps Key -> Node pointer
    Node* head; // Dummy head
    Node* tail; // Dummy tail

    // --- Helper Functions for the Linked List ---

    // Always add a new node right after the dummy head (Most Recently Used)
    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    // Remove an existing node from the linked list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Move a node to the very front (after dummy head)
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    // Remove the node right before the dummy tail (Least Recently Used)
    Node* popTail() {
        Node* lruNode = tail->prev;
        removeNode(lruNode);
        return lruNode;
    }

public:
    // 2. Initialize the Cache and our Dummy anchors
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); // -1 given to values to let us know that they are dummy.
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    // 3. GET Operation
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Since we just accessed it, it becomes the most recently used!
            moveToHead(node); 
            return node->val;
        }
        return -1; // Key not found
    }
    
    // 4. PUT Operation
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Update the existing node's value if it exists, and bring it to the front
            Node* node = cache[key];
            node->val = value;
            moveToHead(node);
        } else {
            // Create a brand new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);

            // If we exceed capacity, evict the LRU item
            if (cache.size() > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key); // Remove from hash map
                delete tailNode;            // Prevent memory leak
            }
        }
    }
};