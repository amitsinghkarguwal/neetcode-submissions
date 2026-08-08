#include <string>
using namespace std;

class TrieNode {
public:
    // Array to hold pointers to child nodes (for 26 lowercase English letters)
    TrieNode* children[26];
    // Flag to mark the end of a valid inserted word
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        // Initialize all children to nullptr
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class PrefixTree {
private:
    TrieNode* root;

public:
    PrefixTree() {
        // The root node acts as a dummy node (doesn't hold a character itself)
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a'; // Map 'a'-'z' to 0-25
            // If the path doesn't exist, create a new node
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            // Move down the tree
            curr = curr->children[index];
        }
        // Mark the final node as the end of the word
        curr->isEndOfWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            // If the path breaks, the word doesn't exist
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        // Return true ONLY if we actually inserted this exact word
        return curr->isEndOfWord;
    }
    
    // Returns if there is any word in the trie that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';
            // If the path breaks, no word has this prefix
            if (curr->children[index] == nullptr) {
                return false;
            }
            curr = curr->children[index];
        }
        // If we successfully traced the prefix, it exists
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */