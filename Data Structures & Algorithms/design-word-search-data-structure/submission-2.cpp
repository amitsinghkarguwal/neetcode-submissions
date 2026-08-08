#include <string>
#include <vector>

using namespace std;

// Step 1: Define the Trie Node
class TrieNode {
public:
    TrieNode* children[26];
    bool is_word;
    
    TrieNode() {
        is_word = false;
        // Initialize all 26 child pointers to null
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
private:
    TrieNode* root;
    
    // Recursive DFS helper for wildcard searching
    bool searchHelper(const string& word, int index, TrieNode* node) {
        // Base case: we reached the end of the search string
        if (index == word.length()) {
            return node->is_word;
        }
        
        char c = word[index];
        
        if (c == '.') {
            // Wildcard: Try all 26 possible paths
            for (int i = 0; i < 26; i++) {
                if (node->children[i] != nullptr) {
                    if (searchHelper(word, index + 1, node->children[i])) {
                        return true; 
                    }
                }
            }
            // If all 26 paths lead to a dead end, this search fails
            return false;
        } else {
            // Standard character lookup
            int childIndex = c - 'a';
            if (node->children[childIndex] == nullptr) {
                return false; // Dead end
            }
            // Continue down the single correct path
            return searchHelper(word, index + 1, node->children[childIndex]);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        // Mark the end of the word
        curr->is_word = true;
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};