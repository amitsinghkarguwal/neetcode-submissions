#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}  //new way to make a function.
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache; // Maps Key -> Node pointer
    Node* head; // Dummy head
    Node* tail; // Dummy tail


    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* lruNode = tail->prev;
        removeNode(lruNode);
        return lruNode;
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1); // -1 given to values to let us know that they are dummy.
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            // Since we just accessed it, it becomes the most recently used!
            moveToHead(node); 
            return node->val;
        }
        return -1; // Key not found
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            moveToHead(node);
        } else {

            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);

            if (cache.size() > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key); // Remove from hash map
                delete tailNode;            // Prevent memory leak
            }
        }
    }
};